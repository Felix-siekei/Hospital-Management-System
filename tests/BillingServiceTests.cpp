
#include <cassert>
#include <iostream>

#include "services/BillingService.h"

void testCreateBill()
{
    BillingRepository repository;
    BillingService service(repository);

    Billing bill(
        1, 101, 201, 5000.0, 0.0,
        "Pending", "2026-10-20");

    assert(service.createBill(bill));
    assert(!service.createBill(bill)); // Duplicate ID

    std::cout << "testCreateBill passed\n";
}

void testRejectInvalidBills()
{
    BillingRepository repository;
    BillingService service(repository);

    Billing invalidId(
        0, 101, 201, 5000.0, 0.0,
        "Pending", "2026-10-20");
    assert(!service.createBill(invalidId));

    Billing negativeAmount(
        2, 101, 201, -500.0, 0.0,
        "Pending", "2026-10-20");
    assert(!service.createBill(negativeAmount));

    Billing overpayment(
        3, 101, 201, 5000.0, 6000.0,
        "Paid", "2026-10-20");
    assert(!service.createBill(overpayment));

    Billing wrongStatus(
        4, 101, 201, 5000.0, 0.0,
        "Paid", "2026-10-20");
    assert(!service.createBill(wrongStatus));

    std::cout << "testRejectInvalidBills passed\n";
}

void testRecordPartialPayment()
{
    BillingRepository repository;
    BillingService service(repository);

    Billing bill(
        1, 101, 201, 5000.0, 0.0,
        "Pending", "2026-10-20");
    assert(service.createBill(bill));

    assert(service.recordPayment(1, 2000.0));

    Billing *found = service.findBillById(1);
    assert(found != nullptr);
    assert(found->getAmountPaid() == 2000.0);
    assert(found->getBalance() == 3000.0);
    assert(found->getPaymentStatus() == "Partially Paid");

    std::cout << "testRecordPartialPayment passed\n";
}

void testRecordFullPayment()
{
    BillingRepository repository;
    BillingService service(repository);

    Billing bill(
        1, 101, 201, 5000.0, 2000.0,
        "Partially Paid", "2026-10-20");
    assert(service.createBill(bill));

    assert(service.recordPayment(1, 3000.0));

    Billing *found = service.findBillById(1);
    assert(found != nullptr);
    assert(found->getAmountPaid() == 5000.0);
    assert(found->getBalance() == 0.0);
    assert(found->getPaymentStatus() == "Paid");

    std::cout << "testRecordFullPayment passed\n";
}

void testRejectInvalidPayments()
{
    BillingRepository repository;
    BillingService service(repository);

    Billing bill(
        1, 101, 201, 5000.0, 2000.0,
        "Partially Paid", "2026-10-20");
    assert(service.createBill(bill));

    assert(!service.recordPayment(1, -100.0));
    assert(!service.recordPayment(1, 0.0));
    assert(!service.recordPayment(1, 4000.0));
    assert(!service.recordPayment(99, 100.0));

    std::cout << "testRejectInvalidPayments passed\n";
}

void testCancelBill()
{
    BillingRepository repository;
    BillingService service(repository);

    Billing bill(
        1, 101, 201, 5000.0, 0.0,
        "Pending", "2026-10-20");
    assert(service.createBill(bill));

    assert(service.cancelBill(1));
    assert(service.findBillById(1) == nullptr);
    assert(!service.cancelBill(1));
    assert(!service.cancelBill(0));

    std::cout << "testCancelBill passed\n";
}

int main()
{
    testCreateBill();
    testRejectInvalidBills();
    testRecordPartialPayment();
    testRecordFullPayment();
    testRejectInvalidPayments();
    testCancelBill();

    std::cout << "\nAll Billing service tests passed!\n";

    return 0;
}

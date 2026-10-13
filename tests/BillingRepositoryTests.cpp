
#include <cassert>
#include <iostream>

#include "repositories/BillingRepository.h"

void testAddBill()
{
    BillingRepository repository;

    Billing bill(
        1, 101, 201, 5000.0, 2000.0,
        "Partially Paid", "2026-10-20");

    assert(repository.add(bill));
    assert(!repository.add(bill));

    std::cout << "testAddBill passed\n";
}

void testFindBill()
{
    BillingRepository repository;

    Billing bill(
        1, 101, 201, 5000.0, 2000.0,
        "Partially Paid", "2026-10-20");

    repository.add(bill);

    Billing *found = repository.findById(1);

    assert(found != nullptr);
    assert(found->getPatientId() == 101);
    assert(found->getBalance() == 3000.0);
    assert(repository.findById(99) == nullptr);

    std::cout << "testFindBill passed\n";
}

void testGetAllBills()
{
    BillingRepository repository;

    Billing first(
        1, 101, 201, 5000.0, 2000.0,
        "Partially Paid", "2026-10-20");

    Billing second(
        2, 102, 202, 3000.0, 0.0,
        "Pending", "2026-10-21");

    repository.add(first);
    repository.add(second);

    assert(repository.getAll().size() == 2);

    std::cout << "testGetAllBills passed\n";
}

void testUpdateBill()
{
    BillingRepository repository;

    Billing bill(
        1, 101, 201, 5000.0, 2000.0,
        "Partially Paid", "2026-10-20");

    repository.add(bill);

    Billing updated(
        1, 101, 201, 5000.0, 5000.0,
        "Paid", "2026-10-20");

    assert(repository.update(updated));

    Billing *found = repository.findById(1);

    assert(found != nullptr);
    assert(found->getAmountPaid() == 5000.0);
    assert(found->getBalance() == 0.0);
    assert(found->getPaymentStatus() == "Paid");

    Billing missing(
        99, 101, 201, 5000.0, 5000.0,
        "Paid", "2026-10-20");

    assert(!repository.update(missing));

    std::cout << "testUpdateBill passed\n";
}

void testRemoveBill()
{
    BillingRepository repository;

    Billing bill(
        1, 101, 201, 5000.0, 2000.0,
        "Partially Paid", "2026-10-20");

    repository.add(bill);

    assert(repository.remove(1));
    assert(repository.findById(1) == nullptr);
    assert(!repository.remove(1));

    std::cout << "testRemoveBill passed\n";
}

int main()
{
    testAddBill();
    testFindBill();
    testGetAllBills();
    testUpdateBill();
    testRemoveBill();

    std::cout << "\nAll Billing repository tests passed!\n";

    return 0;
}

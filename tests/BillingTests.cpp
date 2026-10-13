
#include <cassert>
#include <iostream>

#include "models/Billing.h"

void testBillingConstructorAndGetters()
{
    Billing bill(
        1, 101, 201, 5000.0, 2000.0,
        "Partially Paid", "2026-10-20");

    assert(bill.getId() == 1);
    assert(bill.getPatientId() == 101);
    assert(bill.getAppointmentId() == 201);
    assert(bill.getTotalAmount() == 5000.0);
    assert(bill.getAmountPaid() == 2000.0);
    assert(bill.getPaymentStatus() == "Partially Paid");
    assert(bill.getBillingDate() == "2026-10-20");

    std::cout << "testBillingConstructorAndGetters passed\n";
}

void testBalanceCalculation()
{
    Billing bill(
        1, 101, 201, 5000.0, 2000.0,
        "Partially Paid", "2026-10-20");

    assert(bill.getBalance() == 3000.0);

    std::cout << "testBalanceCalculation passed\n";
}

void testBillingSetters()
{
    Billing bill(
        1, 101, 201, 5000.0, 2000.0,
        "Partially Paid", "2026-10-20");

    bill.setAmountPaid(5000.0);
    bill.setPaymentStatus("Paid");

    assert(bill.getAmountPaid() == 5000.0);
    assert(bill.getBalance() == 0.0);
    assert(bill.getPaymentStatus() == "Paid");

    std::cout << "testBillingSetters passed\n";
}

int main()
{
    testBillingConstructorAndGetters();
    testBalanceCalculation();
    testBillingSetters();

    std::cout << "\nAll Billing model tests passed!\n";

    return 0;
}

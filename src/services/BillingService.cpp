
#include "services/BillingService.h"

BillingService::BillingService(BillingRepository &repository)
    : repository(repository)
{
}

bool BillingService::createBill(const Billing &bill)
{
    if (bill.getId() <= 0 ||
        bill.getPatientId() <= 0 ||
        bill.getAppointmentId() <= 0 ||
        bill.getTotalAmount() <= 0 ||
        bill.getAmountPaid() < 0 ||
        bill.getAmountPaid() > bill.getTotalAmount() ||
        bill.getBillingDate().empty())
    {
        return false;
    }

    std::string expectedStatus;

    if (bill.getAmountPaid() == 0)
    {
        expectedStatus = "Pending";
    }
    else if (bill.getAmountPaid() < bill.getTotalAmount())
    {
        expectedStatus = "Partially Paid";
    }
    else
    {
        expectedStatus = "Paid";
    }

    if (bill.getPaymentStatus() != expectedStatus)
    {
        return false;
    }

    return repository.add(bill);
}

Billing *BillingService::findBillById(int id)
{
    if (id <= 0)
    {
        return nullptr;
    }

    return repository.findById(id);
}

bool BillingService::recordPayment(int billId, double amount)
{
    if (billId <= 0 || amount <= 0)
    {
        return false;
    }

    Billing *bill = repository.findById(billId);

    if (bill == nullptr)
    {
        return false;
    }

    double balance = bill->getBalance();

    if (amount > balance)
    {
        return false;
    }

    double newAmountPaid = bill->getAmountPaid() + amount;
    bill->setAmountPaid(newAmountPaid);

    if (newAmountPaid == bill->getTotalAmount())
    {
        bill->setPaymentStatus("Paid");
    }
    else
    {
        bill->setPaymentStatus("Partially Paid");
    }

    return true;
}

bool BillingService::cancelBill(int id)
{
    if (id <= 0)
    {
        return false;
    }

    return repository.remove(id);
}

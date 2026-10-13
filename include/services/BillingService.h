
#pragma once

#include "repositories/BillingRepository.h"

class BillingService
{
private:
    BillingRepository &repository;

public:
    explicit BillingService(BillingRepository &repository);

    bool createBill(const Billing &bill);
    Billing *findBillById(int id);
    bool recordPayment(int billId, double amount);
    bool cancelBill(int id);
};

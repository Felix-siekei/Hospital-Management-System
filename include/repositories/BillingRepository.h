#pragma once
#include "models/Billing.h"
#include <vector>
class BillingRepository{
    private:
        std::vector<Billing>  bills;
    public:
    bool add(const Billing& bill);
    std::vector<Billing> getAll() const;
    Billing *findById(int id);
    bool update(const Billing& bill);
    bool remove(int id);
};
#include "repositories/BillingRepository.h"

bool BillingRepository::add(const Billing& bill){
    if(findById(bill.getId()) !=  nullptr){
        return false;
    }
     bills.push_back(bill);
     return true;

}

std::vector<Billing> BillingRepository::getAll()const{
    return bills;
}

Billing* BillingRepository::findById(int id){
    for(auto& bill:bills){
        if(bill.getId() == id){
            return &bill;
        }
    }
    return nullptr;
}

bool BillingRepository::update(const Billing& bill){
    Billing *existing = findById(bill.getId());

    if (existing == nullptr){
        return false;
    }
    existing ->setAmountPaid(bill.getAmountPaid());
    existing -> setPaymentStatus(bill.getPaymentStatus());
    return true;
}

bool BillingRepository::remove(int id){
    for(auto it = bills.begin(); it != bills.end(); ++it){
        if(it->getId() == id){
            bills.erase(it);
            return true;
        }
    }
    return false;
}
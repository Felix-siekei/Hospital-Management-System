
#pragma once

#include <string>

class Billing
{
private:
    int id;
    int patientId;
    int appointmentId;
    double totalAmount;
    double amountPaid;
    std::string paymentStatus;
    std::string billingDate;

public:
    Billing(
        int id,
        int patientId,
        int appointmentId,
        double totalAmount,
        double amountPaid,
        const std::string &paymentStatus,
        const std::string &billingDate);

    int getId() const;
    int getPatientId() const;
    int getAppointmentId() const;
    double getTotalAmount() const;
    double getAmountPaid() const;
    double getBalance() const;
    const std::string &getPaymentStatus() const;
    const std::string &getBillingDate() const;

    void setAmountPaid(double amountPaid);
    void setPaymentStatus(const std::string &paymentStatus);
};

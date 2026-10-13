
#include "models/Billing.h"

Billing::Billing(
    int id,
    int patientId,
    int appointmentId,
    double totalAmount,
    double amountPaid,
    const std::string &paymentStatus,
    const std::string &billingDate)
    : id(id),
      patientId(patientId),
      appointmentId(appointmentId),
      totalAmount(totalAmount),
      amountPaid(amountPaid),
      paymentStatus(paymentStatus),
      billingDate(billingDate)
{
}

int Billing::getId() const
{
    return id;
}

int Billing::getPatientId() const
{
    return patientId;
}

int Billing::getAppointmentId() const
{
    return appointmentId;
}

double Billing::getTotalAmount() const
{
    return totalAmount;
}

double Billing::getAmountPaid() const
{
    return amountPaid;
}

double Billing::getBalance() const
{
    return totalAmount - amountPaid;
}

const std::string &Billing::getPaymentStatus() const
{
    return paymentStatus;
}

const std::string &Billing::getBillingDate() const
{
    return billingDate;
}

void Billing::setAmountPaid(double amountPaid)
{
    this->amountPaid = amountPaid;
}

void Billing::setPaymentStatus(const std::string &paymentStatus)
{
    this->paymentStatus = paymentStatus;
}

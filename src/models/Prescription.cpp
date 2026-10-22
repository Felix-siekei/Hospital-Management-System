
#include "models/Prescription.h"

Prescription::Prescription(
    int id,
    int patientId,
    int doctorId,
    const std::string &medicationName,
    const std::string &dosage,
    const std::string &frequency,
    const std::string &startDate,
    const std::string &endDate,
    const std::string &status)
    : id(id),
      patientId(patientId),
      doctorId(doctorId),
      medicationName(medicationName),
      dosage(dosage),
      frequency(frequency),
      startDate(startDate),
      endDate(endDate),
      status(status) {}

int Prescription::getId() const
{
    return id;
}

int Prescription::getPatientId() const
{
    return patientId;
}

int Prescription::getDoctorId() const
{
    return doctorId;
}

const std::string &Prescription::getMedicationName() const
{
    return medicationName;
}

const std::string &Prescription::getDosage() const
{
    return dosage;
}

const std::string &Prescription::getFrequency() const
{
    return frequency;
}

const std::string &Prescription::getStartDate() const
{
    return startDate;
}

const std::string &Prescription::getEndDate() const
{
    return endDate;
}

const std::string &Prescription::getStatus() const
{
    return status;
}

void Prescription::setMedicationName(const std::string &value)
{
    medicationName = value;
}

void Prescription::setDosage(const std::string &value)
{
    dosage = value;
}

void Prescription::setFrequency(const std::string &value)
{
    frequency = value;
}

void Prescription::setStartDate(const std::string &value)
{
    startDate = value;
}

void Prescription::setEndDate(const std::string &value)
{
    endDate = value;
}

void Prescription::setStatus(const std::string &value)
{
    status = value;
}

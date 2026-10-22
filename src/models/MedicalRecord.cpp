#include "models/MedicalRecord.h"

MedicalRecord::MedicalRecord(
    int id,
    int patientId,
    int doctorId,
    const std::string &diagnosis,
    const std::string &symptoms,
    const std::string &treatment,
    const std::string &recordDate)
    : id(id),
      patientId(patientId),
      doctorId(doctorId),
      diagnosis(diagnosis),
      symptoms(symptoms),
      treatment(treatment),
      recordDate(recordDate) {}

int MedicalRecord::getId() const
{
    return id;
}

int MedicalRecord::getPatientId() const
{
    return patientId;
}

int MedicalRecord::getDoctorId() const
{
    return doctorId;
}

const std::string &MedicalRecord::getDiagnosis() const
{
    return diagnosis;
}

const std::string &MedicalRecord::getSymptoms() const
{
    return symptoms;
}

const std::string &MedicalRecord::getTreatment() const
{
    return treatment;
}

const std::string &MedicalRecord::getRecordDate() const
{
    return recordDate;
}

void MedicalRecord::setDiagnosis(const std::string &diagnosis)
{
    this->diagnosis = diagnosis;
}

void MedicalRecord::setSymptoms(const std::string &symptoms)
{
    this->symptoms = symptoms;
}

void MedicalRecord::setTreatment(const std::string &treatment)
{
    this->treatment = treatment;
}
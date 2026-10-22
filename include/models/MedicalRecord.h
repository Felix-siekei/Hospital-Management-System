#pragma once

#include <string>

class MedicalRecord
{
private:
    int id;
    int patientId;
    int doctorId;
    std::string diagnosis;
    std::string symptoms;
    std::string treatment;
    std::string recordDate;

public:
    MedicalRecord(
        int id,
        int patientId,
        int doctorId,
        const std::string &diagnosis,
        const std::string &symptoms,
        const std::string &treatment,
        const std::string &recordDate);

    int getId() const;
    int getPatientId() const;
    int getDoctorId() const;

    const std::string &getDiagnosis() const;
    const std::string &getSymptoms() const;
    const std::string &getTreatment() const;
    const std::string &getRecordDate() const;

    void setDiagnosis(const std::string &diagnosis);
    void setSymptoms(const std::string &symptoms);
    void setTreatment(const std::string &treatment);
};
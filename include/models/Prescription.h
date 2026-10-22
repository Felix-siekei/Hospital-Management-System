
#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include <string>

class Prescription
{
private:
    int id;
    int patientId;
    int doctorId;
    std::string medicationName;
    std::string dosage;
    std::string frequency;
    std::string startDate;
    std::string endDate;
    std::string status;

public:
    Prescription(
        int id,
        int patientId,
        int doctorId,
        const std::string &medicationName,
        const std::string &dosage,
        const std::string &frequency,
        const std::string &startDate,
        const std::string &endDate,
        const std::string &status = "Active");

    int getId() const;
    int getPatientId() const;
    int getDoctorId() const;

    const std::string &getMedicationName() const;
    const std::string &getDosage() const;
    const std::string &getFrequency() const;
    const std::string &getStartDate() const;
    const std::string &getEndDate() const;
    const std::string &getStatus() const;

    void setMedicationName(const std::string &value);
    void setDosage(const std::string &value);
    void setFrequency(const std::string &value);
    void setStartDate(const std::string &value);
    void setEndDate(const std::string &value);
    void setStatus(const std::string &value);
};

#endif

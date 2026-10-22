
#ifndef PRESCRIPTION_SERVICE_H
#define PRESCRIPTION_SERVICE_H

#include "repositories/PrescriptionRepository.h"
#include <string>
#include <vector>

class PrescriptionService
{
private:
    PrescriptionRepository &repository;

    static bool isValidIsoDate(const std::string &date);
    static bool isValidStatus(const std::string &status);
    static bool isValidPrescription(const Prescription &prescription);

public:
    explicit PrescriptionService(PrescriptionRepository &repository);

    bool createPrescription(const Prescription &prescription);

    Prescription *findPrescriptionById(int id);

    std::vector<Prescription> getAllPrescriptions() const;

    std::vector<Prescription> getPatientPrescriptions(int patientId) const;

    bool updatePrescription(const Prescription &prescription);

    bool cancelPrescription(int id);
    bool completePrescription(int id);

    bool removePrescription(int id);
};

#endif

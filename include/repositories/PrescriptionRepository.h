
#ifndef PRESCRIPTION_REPOSITORY_H
#define PRESCRIPTION_REPOSITORY_H

#include "models/Prescription.h"
#include <vector>

class PrescriptionRepository
{
private:
    std::vector<Prescription> prescriptions;

public:
    bool add(const Prescription &prescription);

    Prescription *findById(int id);
    const Prescription *findById(int id) const;

    std::vector<Prescription> getAll() const;
    std::vector<Prescription> findByPatientId(int patientId) const;

    bool update(const Prescription &prescription);
    bool remove(int id);
};

#endif

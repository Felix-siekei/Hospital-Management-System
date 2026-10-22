
#include "repositories/PrescriptionRepository.h"

bool PrescriptionRepository::add(
    const Prescription &prescription)
{
    if (prescription.getId() <= 0 ||
        findById(prescription.getId()) != nullptr)
    {
        return false;
    }

    prescriptions.push_back(prescription);
    return true;
}

Prescription *PrescriptionRepository::findById(int id)
{
    for (auto &prescription : prescriptions)
    {
        if (prescription.getId() == id)
        {
            return &prescription;
        }
    }

    return nullptr;
}

const Prescription *PrescriptionRepository::findById(int id) const
{
    for (const auto &prescription : prescriptions)
    {
        if (prescription.getId() == id)
        {
            return &prescription;
        }
    }

    return nullptr;
}

std::vector<Prescription> PrescriptionRepository::getAll() const
{
    return prescriptions;
}

std::vector<Prescription>
PrescriptionRepository::findByPatientId(int patientId) const
{
    std::vector<Prescription> result;

    for (const auto &prescription : prescriptions)
    {
        if (prescription.getPatientId() == patientId)
        {
            result.push_back(prescription);
        }
    }

    return result;
}

bool PrescriptionRepository::update(
    const Prescription &prescription)
{
    Prescription *existing = findById(prescription.getId());

    if (existing == nullptr)
    {
        return false;
    }

    *existing = prescription;
    return true;
}

bool PrescriptionRepository::remove(int id)
{
    for (auto it = prescriptions.begin();
         it != prescriptions.end(); ++it)
    {
        if (it->getId() == id)
        {
            prescriptions.erase(it);
            return true;
        }
    }

    return false;
}

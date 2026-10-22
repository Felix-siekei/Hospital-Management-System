
#include "services/PrescriptionService.h"

#include <cctype>

PrescriptionService::PrescriptionService(
    PrescriptionRepository &repository)
    : repository(repository) {}

bool PrescriptionService::isValidIsoDate(
    const std::string &date)
{
    if (date.size() != 10 ||
        date[4] != '-' ||
        date[7] != '-')
    {
        return false;
    }

    for (std::size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
        {
            continue;
        }

        if (!std::isdigit(
                static_cast<unsigned char>(date[i])))
        {
            return false;
        }
    }

    int month = (date[5] - '0') * 10 + (date[6] - '0');
    int day = (date[8] - '0') * 10 + (date[9] - '0');

    return month >= 1 && month <= 12 &&
           day >= 1 && day <= 31;
}

bool PrescriptionService::isValidStatus(
    const std::string &status)
{
    return status == "Active" ||
           status == "Completed" ||
           status == "Cancelled";
}

bool PrescriptionService::isValidPrescription(
    const Prescription &prescription)
{
    return prescription.getId() > 0 &&
           prescription.getPatientId() > 0 &&
           prescription.getDoctorId() > 0 &&
           !prescription.getMedicationName().empty() &&
           !prescription.getDosage().empty() &&
           !prescription.getFrequency().empty() &&
           isValidIsoDate(prescription.getStartDate()) &&
           isValidIsoDate(prescription.getEndDate()) &&
           prescription.getStartDate() <= prescription.getEndDate() &&
           isValidStatus(prescription.getStatus());
}

bool PrescriptionService::createPrescription(
    const Prescription &prescription)
{
    if (!isValidPrescription(prescription))
    {
        return false;
    }

    return repository.add(prescription);
}

Prescription *PrescriptionService::findPrescriptionById(int id)
{
    if (id <= 0)
    {
        return nullptr;
    }

    return repository.findById(id);
}

std::vector<Prescription>
PrescriptionService::getAllPrescriptions() const
{
    return repository.getAll();
}

std::vector<Prescription>
PrescriptionService::getPatientPrescriptions(int patientId) const
{
    if (patientId <= 0)
    {
        return {};
    }

    return repository.findByPatientId(patientId);
}

bool PrescriptionService::updatePrescription(
    const Prescription &prescription)
{
    if (!isValidPrescription(prescription))
    {
        return false;
    }

    return repository.update(prescription);
}

bool PrescriptionService::cancelPrescription(int id)
{
    Prescription *prescription = findPrescriptionById(id);

    if (prescription == nullptr ||
        prescription->getStatus() != "Active")
    {
        return false;
    }

    prescription->setStatus("Cancelled");
    return true;
}

bool PrescriptionService::completePrescription(int id)
{
    Prescription *prescription = findPrescriptionById(id);

    if (prescription == nullptr ||
        prescription->getStatus() != "Active")
    {
        return false;
    }

    prescription->setStatus("Completed");
    return true;
}

bool PrescriptionService::removePrescription(int id)
{
    if (id <= 0)
    {
        return false;
    }

    return repository.remove(id);
}

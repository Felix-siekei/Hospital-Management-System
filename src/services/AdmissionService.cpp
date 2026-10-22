#include "services/AdmissionService.h"

#include <algorithm>

AdmissionService::AdmissionService(AdmissionRepository &repository)
    : repository(repository) {}

bool AdmissionService::admitPatient(const Admission &admission)
{
    if (admission.getId() <= 0 ||
        admission.getPatientId() <= 0 ||
        admission.getWard().empty() ||
        admission.getBedNumber().empty() ||
        admission.getAdmissionDate().empty() ||
        admission.getStatus() != "Admitted" ||
        !admission.getDischargeDate().empty())
    {
        return false;
    }

    return repository.add(admission);
}

Admission *AdmissionService::findAdmissionById(int id)
{
    if (id <= 0)
    {
        return nullptr;
    }

    return repository.findById(id);
}

std::vector<Admission> AdmissionService::getAllAdmissions() const
{
    return repository.getAll();
}

bool AdmissionService::dischargePatient(
    int admissionId,
    const std::string &dischargeDate)
{
    if (admissionId <= 0 || dischargeDate.empty())
    {
        return false;
    }

    Admission *admission = repository.findById(admissionId);

    if (admission == nullptr || admission->getStatus() != "Admitted")
    {
        return false;
    }

    if (dischargeDate < admission->getAdmissionDate())
    {
        return false;
    }

    admission->setDischargeDate(dischargeDate);
    admission->setStatus("Discharged");

    return true;
}

bool AdmissionService::removeAdmission(int id)
{
    if (id <= 0)
    {
        return false;
    }

    return repository.remove(id);
}
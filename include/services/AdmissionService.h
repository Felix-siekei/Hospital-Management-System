#pragma once

#include <vector>

#include "models/Admission.h"
#include "repositories/AdmissionRepository.h"

class AdmissionService
{
private:
    AdmissionRepository &repository;

public:
    explicit AdmissionService(AdmissionRepository &repository);

    bool admitPatient(const Admission &admission);
    Admission *findAdmissionById(int id);
    std::vector<Admission> getAllAdmissions() const;
    bool dischargePatient(int admissionId, const std::string &dischargeDate);
    bool removeAdmission(int id);
};
#pragma once
#include "models/Patient.h"
#include "repositories/PatientRepository.h"
#include <optional>


class PatientService{
    private:
    PatientRepository& repository;


    public:
    PatientService(PatientRepository& repositories);

    bool registerPatient( Patient& patient);

    std::optional<Patient> findPatientById(int id) const;
};
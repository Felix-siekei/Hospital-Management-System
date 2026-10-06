#pragma once
#include "models/Patient.h"
#include "repositories/ PatientRepository.h"



class PatientService{
    private:
    PatientRepository& repository;


    public:
    PatientService(PatientRepository& repositories);

    bool registerPatient(const Patient& patient);

    const Patient* findPatientById(int id) const;
};
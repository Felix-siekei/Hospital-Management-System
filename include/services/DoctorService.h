#pragma once

#include "models/Doctor.h"
#include "repositories/DoctorRepository.h"

class DoctorService {
private:
    DoctorRepository& repository;

public:
    DoctorService(DoctorRepository& repository);

    bool registerDoctor(const Doctor& doctor);

    const Doctor* findDoctorById(int id) const;
};
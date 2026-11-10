#pragma once
#include <optional>
#include "models/Doctor.h"
#include "repositories/DoctorRepository.h"

class DoctorService {
private:
    DoctorRepository& repository;

public:
    DoctorService(DoctorRepository& repository);

    bool registerDoctor( Doctor& doctor);

    std::optional<Doctor> findDoctorById(int id) const;
};
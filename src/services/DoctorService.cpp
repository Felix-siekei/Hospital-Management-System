#include "services/DoctorService.h"

DoctorService::DoctorService(DoctorRepository& repository)
    : repository(repository) {
}

bool DoctorService::registerDoctor(Doctor& doctor) {

    if (doctor.getSpecialization().empty()) {
        return false;
    }

    return repository.add(doctor);
}

std::optional<Doctor> DoctorService::findDoctorById(int id) const {
    return repository.findById(id);
}
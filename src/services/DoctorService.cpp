#include "services/DoctorService.h"

DoctorService::DoctorService(DoctorRepository& repository)
    : repository(repository) {
}

bool DoctorService::registerDoctor(const Doctor& doctor) {

    if (doctor.getId() <= 0) {
        return false;
    }

    if (doctor.getSpecialization().empty()) {
        return false;
    }

    repository.add(doctor);

    return true;
}

const Doctor* DoctorService::findDoctorById(int id) const {
    return repository.findById(id);
}
#include "services/PatientService.h"


PatientService::PatientService(PatientRepository& repository)
    : repository(repository) { 

    };

bool PatientService::registerPatient(const Patient& patient){

    if( patient.getAge() < 0){
        return false;
    }
    repository.add(patient);
    return true;
};

const Patient* PatientService::findPatientById(int id) const {
    return repository.findById(id);
}


#include "repositories/ PatientRepository.h"


void PatientRepository::add(const Patient& patient){


    patients.push_back(patient);
};


const std::vector<Patient>& PatientRepository::getAll() const {
    return patients;
};


const Patient* PatientRepository::findById(int id) const{
    for (const auto& patient : patients){

        if(patient.getId() == id){
            return &patient;
        }

    }
    return nullptr;
}



bool PatientRepository::update(const Patient& updatedPatient){
    for (auto& patient: patients){
        if(patient.getId() == updatedPatient.getId()){
            patient.setFirstName(updatedPatient.getFirstName());
            patient.setLastName(updatedPatient.getLastName());
            patient.setAge(updatedPatient.getAge());
            patient.setPhone(updatedPatient.getPhone());

            return true;

        }
    }
    return false;
}


bool PatientRepository::remove(int id){
    for(auto it = patients.begin(); it != patients.end(); ++it){
        if(it->getId()){
            patients.erase(it);
            return true;
        }
    }
    return false
}
























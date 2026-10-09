#include "repositories/DoctorRepository.h"

void DoctorRepository::add(const Doctor& doctor){
    doctors.push_back(doctor);
}


const std::vector<Doctor>& DoctorRepository::getAll() const{
    return doctors;
}

const Doctor* DoctorRepository::findById(int id ) const{
    for(const auto& doctor: doctors){
        if(doctor.getId() == id){
            return &doctor;
            
        }
    }
    return nullptr;


}


bool DoctorRepository::update(const Doctor& updatedDoctor){
    for(auto& doctor: doctors){
        if(doctor.getId() == updatedDoctor.getId()){
            doctor.setFirstName(updatedDoctor.getFirstName());
            doctor.setLastName(updatedDoctor.getLastName());
            doctor.setSpecialization(updatedDoctor.getSpecialization());
            doctor.setPhone(updatedDoctor.getPhone());

            return true;


        }

    }
    return false;
}


bool DoctorRepository::remove(int id){
    for (auto it= doctors.begin(); it != doctors.end(); ++it){
        if(it->getId() == id){
            doctors.erase(it);
            return true;  
        }
    }
    return false;
}




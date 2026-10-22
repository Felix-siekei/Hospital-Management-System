#include "repositories/AdmissionRepository.h"



bool AdmissionRepository::add(const Admission& admission){
    if(findById(admission.getId())  != nullptr){
        return false;
    }
    admissions.push_back(admission);
    return true;
}

Admission* AdmissionRepository::findById(int id){
    for (auto &admission :admissions){
        if(admission.getId() == id){
            return &admission;
        }
    }
    return nullptr;
}

std::vector<Admission> AdmissionRepository::getAll()const{
    return admissions;
}

bool AdmissionRepository::update(const Admission& admission){
    Admission* existingAdmission = findById(admission.getId());
    if(existingAdmission == nullptr){
        return false;
    }
    *existingAdmission = admission;
    return true;
}

bool AdmissionRepository::remove(int id){
    for(auto it= admissions.begin(); it != admissions.end(); ++it){
        if(it-> getId() == id){
            admissions.erase(it);
            return true;
        }
    }
    return false;
}
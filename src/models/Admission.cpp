#include "models/Admission.h"
Admission::Admission(int id,
                     int patientId,
                     const std::string &ward,
                     const std::string &bedNumber,
                     const std::string &admissionDate,
                     const std::string &dischargeDate,
                     const std::string &status)
    : id(id),
      patientId(patientId),
      ward(ward),
      bedNumber(bedNumber),
      admissionDate(admissionDate),
      dischargeDate(dischargeDate),
      status(status){}


//define getters

int Admission::getId( )const {
    return id;
};

int Admission::getPatientId()const{
    return patientId;
    
}
const std::string& Admission::getAdmissionDate()const{
    return admissionDate;
}
const std::string& Admission::getWard()const{
    return ward;
}
const std::string& Admission::getBedNumber()const{
    return bedNumber;
}
const std::string& Admission::getStatus()const{
    return status;
}

const std::string& Admission::getDischargeDate() const{
    return dischargeDate;
}

//setters

void Admission::setWard(const std::string& ward){
    this->ward = ward;
}

void Admission::setBedNumber(const std::string& bedNumber){
    this->bedNumber = bedNumber;
}
void Admission::setDischargeDate(const std::string &dischargeDate){
    this->dischargeDate = dischargeDate;
}
void Admission::setStatus(const std::string &status){
    this->status = status;
}
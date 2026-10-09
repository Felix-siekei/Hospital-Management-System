#include "models/Doctor.h"


Doctor::Doctor(   
        int id,
        const std::string& firstName,
        const std::string& lastName,
        const std::string& specialization,
        const std::string& phone

):

    id(id),
    firstName(firstName),
    lastName(lastName),
    specialization(specialization),
    phone(phone){



    };



    int Doctor::getId() const {
        return id;
    }

    const std::string& Doctor::getFirstName() const{
        return firstName;
    }

    const std::string& Doctor::getLastName() const{
        return lastName;
    }

    const std::string& Doctor::getSpecialization() const{
        return specialization;
    }
    const std::string&  Doctor::getPhone() const{
        return phone;
    }


    void Doctor::setFirstName(const std::string& firstName){
        this->firstName = firstName;
    }
    void Doctor::setLastName(const std::string& lastName){
        this->lastName =lastName;
    }
    void Doctor::setSpecialization(const std::string& specialization){
        this->specialization= specialization;
    }
    void Doctor::setPhone(const std::string& phone){
        this->phone= phone;
    }





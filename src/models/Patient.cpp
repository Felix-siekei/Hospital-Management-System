#include "models/Patient.h"

 //implementation file for Patient

Patient::Patient(
    int id,
    const std::string& firstName,
    const std::string& lastName,
    int age,
    const std::string& phone
)
    : id(id),
      firstName(firstName),
      lastName(lastName),
      age(age),
      phone(phone) {
}


//getter

int Patient::getId() const {
    return id;
}

const std::string& Patient::getFirstName() const {
    return firstName;
}

const std::string& Patient::getLastName() const {
    return lastName;
}

int Patient::getAge() const {
    return age;
}

const std::string& Patient::getPhone() const {
    return phone;
}

//setter


void Patient::setFirstName(const std::string& firstName){
    this->firstName = firstName;
}

void Patient::setLastName(const std::string& lastName){
    this->lastName = lastName;
}


void::Patient::setAge(const int age){
    this-> age= age;
}

void Patient::setPhone(const std::string& phone){
    this-> phone  = phone;
}


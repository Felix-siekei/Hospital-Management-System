#pragma once

#include <string>

//declaration file for Patient Object


class Patient {
private:
    int id;
    std::string firstName;
    std::string lastName;
    int age;
    std::string phone;

public:
    Patient(
        int id,
        const std::string& firstName,
        const std::string& lastName,
        int age,
        const std::string& phone
    );
//getter
    int getId() const;
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    int getAge() const;
    const std::string& getPhone() const;

    //setters


    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setAge(int age);
    void setPhone(const std::string& phone);





    




};
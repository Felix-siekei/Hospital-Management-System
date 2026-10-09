#pragma once

#include  <string>


class Doctor {

    private:
        int id;
        std::string firstName;
        std::string lastName;
        std::string specialization;
        std::string phone;

    public:
        Doctor(
            int id,
            const std::string& firstName,
            const std::string& lastName,
            const std::string& specialization,
            const std::string& phone);

        //getter

        int getId() const;

        const std::string& getFirstName() const;

        const std::string& getLastName() const;

        const std::string& getSpecialization() const;

        const std::string& getPhone() const;

        //setter

        void setFirstName(const std::string& firstName);

        void setLastName(const std::string& lastName);

        void setSpecialization(const std::string& specialization);

        void setPhone(const std::string& phone);
};
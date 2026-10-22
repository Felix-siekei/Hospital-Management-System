#pragma once
#include <string>

class Admission{
    private:
        int id;
        int patientId;
        std::string ward;
        std::string bedNumber;
        std::string admissionDate;
        std::string dischargeDate;
        std::string status;
    public:
    Admission( int id,
        int patientId,
        const  std::string& ward,
        const std::string& bedNumber,
        const  std::string& admissionDate,
        const  std::string& dischargeDate,
        const  std::string& status);

        //getter
        int getId() const;
        int getPatientId() const;
        const std::string& getWard() const;
        const std::string& getBedNumber() const;
        const std::string& getAdmissionDate() const;
        const std::string& getDischargeDate() const;
        const std::string &getStatus() const;

        //setter
        void setWard(const std::string &ward);
        void setBedNumber(const std::string &bedNumber);
        void setDischargeDate(const std::string &dischargeDate);
        void setStatus(const std::string &status);
};
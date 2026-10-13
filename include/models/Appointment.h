#pragma once
#include <string>

class Appointment
{
private:
    int id;
    int patientId;
    int doctorId;
    std::string date;
    std::string time;
    std::string status;

public:
    Appointment(int id,
                int patinetId,
                int doctorId,
                const std::string& date,
                const std::string& time,
                const std::string& status);

    int getId() const;
    int getPatientId() const;
    int getDoctorId() const;
    const std::string &getDate() const;
    const std::string &getTime() const;
    const std::string &getStatus() const;

    // setter

    void setDate(const std::string &date);
    void setTime(const std::string &time);
    void setStatus(const std::string &status);
};
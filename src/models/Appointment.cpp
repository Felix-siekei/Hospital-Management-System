
#include "models/Appointment.h"

Appointment::Appointment(
    int id,
    int patientId,
    int doctorId,
    const std::string &date,
    const std::string &time,
    const std::string &status)
    : id(id),
      patientId(patientId),
      doctorId(doctorId),
      date(date),
      time(time),
      status(status)
{
}

int Appointment::getId() const
{
    return id;
}

int Appointment::getPatientId() const
{
    return patientId;
}

int Appointment::getDoctorId() const
{
    return doctorId;
}

const std::string &Appointment::getDate() const
{
    return date;
}

const std::string &Appointment::getTime() const
{
    return time;
}

const std::string &Appointment::getStatus() const
{
    return status;
}

void Appointment::setDate(const std::string &date)
{
    this->date = date;
}

void Appointment::setTime(const std::string &time)
{
    this->time = time;
}

void Appointment::setStatus(const std::string &status)
{
    this->status = status;
}


#include "repositories/AppointmentRepository.h"

bool AppointmentRepository::add(const Appointment &appointment)
{
    if (findById(appointment.getId()) != nullptr)
    {
        return false;
    }

    appointments.push_back(appointment);
    return true;
}

std::vector<Appointment> AppointmentRepository::getAll() const
{
    return appointments;
}

Appointment *AppointmentRepository::findById(int id)
{
    for (auto &appointment : appointments)
    {
        if (appointment.getId() == id)
        {
            return &appointment;
        }
    }

    return nullptr;
}

bool AppointmentRepository::update(const Appointment &appointment)
{
    Appointment *existing = findById(appointment.getId());

    if (existing == nullptr)
    {
        return false;
    }

    existing->setDate(appointment.getDate());
    existing->setTime(appointment.getTime());
    existing->setStatus(appointment.getStatus());

    return true;
}

bool AppointmentRepository::remove(int id)
{
    for (auto it = appointments.begin(); it != appointments.end(); ++it)
    {
        if (it->getId() == id)
        {
            appointments.erase(it);
            return true;
        }
    }

    return false;
}

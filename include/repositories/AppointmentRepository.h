
#pragma once

#include <vector>
#include  "models/Appointment.h"

class AppointmentRepository
{
private:
    std::vector<Appointment> appointments;

public:
    bool add(const Appointment &appointment);
    std::vector<Appointment> getAll() const;
    Appointment *findById(int id);
    bool update(const Appointment &appointment);
    bool remove(int id);
};

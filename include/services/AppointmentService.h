
#pragma once

#include "repositories/AppointmentRepository.h"

class AppointmentService
{
private:
    AppointmentRepository &repository;

public:
    explicit AppointmentService(AppointmentRepository &repository);

    bool scheduleAppointment(const Appointment &appointment);
    Appointment *findAppointmentById(int id);
    bool updateAppointment(const Appointment &appointment);
    bool cancelAppointment(int id);
};

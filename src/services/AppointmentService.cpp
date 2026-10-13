#include "services/AppointmentService.h"

AppointmentService::AppointmentService(AppointmentRepository& repository)
    : repository(repository)
{
}

bool AppointmentService::scheduleAppointment(const Appointment& appointment){

    if (
        appointment.getId() <= 0 ||
        appointment.getPatientId() <= 0 ||
        appointment.getDoctorId() <= 0 ||
        appointment.getDate().empty() ||
        appointment.getTime().empty() ||

        appointment.getStatus() != "Scheduled"

    ){
        return false;
    }
    return repository.add(appointment);
}

Appointment* AppointmentService::findAppointmentById(int id){
    if(id <=0){
        return nullptr;
    }
    return repository.findById(id);
}

bool AppointmentService::updateAppointment(
    const Appointment& appointment
){
    if(
        appointment.getId() <= 0 ||
        appointment.getPatientId() <= 0 ||
        appointment.getDoctorId() <= 0 ||
        appointment.getDate().empty() ||
        appointment.getTime().empty() ||
        (appointment.getStatus() != "Completed" &&
         appointment.getStatus() != "Scheduled" &&
         appointment.getStatus() != "Cancelled"

    ))
    {
        return false;
    }
    return repository.update(appointment);
}

bool AppointmentService::cancelAppointment(int id){
    if(id<=0){
        return false;
    }
    Appointment* appointment = repository.findById(id);
    if(appointment == nullptr){
        return false;

    }
    appointment->setStatus("Cancelled");
    return true;
}


#include <cassert>
#include <iostream>

#include "models/Appointment.h"

void testAppointmentConstructorAndGetters()
{
    Appointment appointment(
        1,
        101,
        201,
        "2026-10-20",
        "09:30",
        "Scheduled");

    assert(appointment.getId() == 1);
    assert(appointment.getPatientId() == 101);
    assert(appointment.getDoctorId() == 201);
    assert(appointment.getDate() == "2026-10-20");
    assert(appointment.getTime() == "09:30");
    assert(appointment.getStatus() == "Scheduled");

    std::cout << "testAppointmentConstructorAndGetters passed\n";
}

void testAppointmentSetters()
{
    Appointment appointment(
        1,
        101,
        201,
        "2026-10-20",
        "09:30",
        "Scheduled");

    appointment.setDate("2026-10-21");
    appointment.setTime("10:30");
    appointment.setStatus("Completed");

    assert(appointment.getDate() == "2026-10-21");
    assert(appointment.getTime() == "10:30");
    assert(appointment.getStatus() == "Completed");

    std::cout << "testAppointmentSetters passed\n";
}

int main()
{
    testAppointmentConstructorAndGetters();
    testAppointmentSetters();

    std::cout << "\nAll Appointment model tests passed!\n";

    return 0;
}

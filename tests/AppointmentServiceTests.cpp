
#include <cassert>
#include <iostream>

#include "services/AppointmentService.h"

void testScheduleAppointment()
{
    AppointmentRepository repository;
    AppointmentService service(repository);

    Appointment appointment(
        1, 101, 201, "2026-10-20", "09:30", "Scheduled");

    assert(service.scheduleAppointment(appointment));
    assert(!service.scheduleAppointment(appointment));

    std::cout << "testScheduleAppointment passed\n";
}

void testRejectInvalidAppointment()
{
    AppointmentRepository repository;
    AppointmentService service(repository);

    Appointment invalidAppointment(
        0, 101, 201, "2026-10-20", "09:30", "Scheduled");

    assert(!service.scheduleAppointment(invalidAppointment));

    Appointment emptyDate(
        2, 101, 201, "", "09:30", "Scheduled");

    assert(!service.scheduleAppointment(emptyDate));

    Appointment invalidStatus(
        3, 101, 201, "2026-10-20", "09:30", "Pending");

    assert(!service.scheduleAppointment(invalidStatus));

    std::cout << "testRejectInvalidAppointment passed\n";
}

void testFindAppointment()
{
    AppointmentRepository repository;
    AppointmentService service(repository);

    Appointment appointment(
        1, 101, 201, "2026-10-20", "09:30", "Scheduled");

    service.scheduleAppointment(appointment);

    assert(service.findAppointmentById(1) != nullptr);
    assert(service.findAppointmentById(99) == nullptr);
    assert(service.findAppointmentById(0) == nullptr);

    std::cout << "testFindAppointment passed\n";
}

void testUpdateAppointment()
{
    AppointmentRepository repository;
    AppointmentService service(repository);

    Appointment appointment(
        1, 101, 201, "2026-10-20", "09:30", "Scheduled");

    service.scheduleAppointment(appointment);

    Appointment updated(
        1, 101, 201, "2026-10-21", "10:30", "Completed");

    assert(service.updateAppointment(updated));

    Appointment *found = service.findAppointmentById(1);
    assert(found != nullptr);
    assert(found->getDate() == "2026-10-21");
    assert(found->getStatus() == "Completed");

    Appointment invalidUpdate(
        1, 101, 201, "2026-10-21", "10:30", "Pending");

    assert(!service.updateAppointment(invalidUpdate));

    std::cout << "testUpdateAppointment passed\n";
}

void testCancelAppointment()
{
    AppointmentRepository repository;
    AppointmentService service(repository);

    Appointment appointment(
        1, 101, 201, "2026-10-20", "09:30", "Scheduled");

    service.scheduleAppointment(appointment);

    assert(service.cancelAppointment(1));

    Appointment *found = service.findAppointmentById(1);
    assert(found != nullptr);
    assert(found->getStatus() == "Cancelled");

    assert(!service.cancelAppointment(99));
    assert(!service.cancelAppointment(0));

    std::cout << "testCancelAppointment passed\n";
}

int main()
{
    testScheduleAppointment();
    testRejectInvalidAppointment();
    testFindAppointment();
    testUpdateAppointment();
    testCancelAppointment();

    std::cout << "\nAll Appointment service tests passed!\n";

    return 0;
}

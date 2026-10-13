
#include <cassert>
#include <iostream>

#include "repositories/AppointmentRepository.h"

void testAddAppointment()
{
    AppointmentRepository repository;

    Appointment appointment(
        1, 101, 201, "2026-10-20", "09:30", "Scheduled");

    assert(repository.add(appointment));
    assert(!repository.add(appointment));

    std::cout << "testAddAppointment passed\n";
}

void testFindAppointment()
{
    AppointmentRepository repository;

    Appointment appointment(
        1, 101, 201, "2026-10-20", "09:30", "Scheduled");

    repository.add(appointment);

    Appointment *found = repository.findById(1);

    assert(found != nullptr);
    assert(found->getPatientId() == 101);
    assert(repository.findById(99) == nullptr);

    std::cout << "testFindAppointment passed\n";
}

void testUpdateAppointment()
{
    AppointmentRepository repository;

    Appointment appointment(
        1, 101, 201, "2026-10-20", "09:30", "Scheduled");

    repository.add(appointment);

    Appointment updated(
        1, 101, 201, "2026-10-21", "10:30", "Completed");

    assert(repository.update(updated));

    Appointment *found = repository.findById(1);

    assert(found != nullptr);
    assert(found->getDate() == "2026-10-21");
    assert(found->getTime() == "10:30");
    assert(found->getStatus() == "Completed");

    assert(!repository.update(
        Appointment(99, 101, 201, "2026-10-21", "10:30", "Completed")));

    std::cout << "testUpdateAppointment passed\n";
}

void testRemoveAppointment()
{
    AppointmentRepository repository;

    Appointment appointment(
        1, 101, 201, "2026-10-20", "09:30", "Scheduled");

    repository.add(appointment);

    assert(repository.remove(1));
    assert(repository.findById(1) == nullptr);
    assert(!repository.remove(1));

    std::cout << "testRemoveAppointment passed\n";
}

int main()
{
    testAddAppointment();
    testFindAppointment();
    testUpdateAppointment();
    testRemoveAppointment();

    std::cout << "\nAll Appointment repository tests passed!\n";

    return 0;
}


#include "services/PrescriptionService.h"

#include <cassert>
#include <iostream>

int main()
{
    PrescriptionRepository repository;
    PrescriptionService service(repository);

    Prescription first(
        1, 10, 20,
        "Example medication",
        "As directed",
        "As directed",
        "2026-01-01",
        "2026-01-07");

    // Create and find a prescription.
    assert(service.createPrescription(first));
    assert(!service.createPrescription(first));
    assert(service.findPrescriptionById(1) != nullptr);
    assert(service.getAllPrescriptions().size() == 1);
    assert(service.getPatientPrescriptions(10).size() == 1);

    // Reject invalid prescription data.
    Prescription invalid(
        2, 10, 20,
        "",
        "As directed",
        "As directed",
        "2026-01-01",
        "2026-01-07");

    assert(!service.createPrescription(invalid));

    // Reject incorrectly formatted dates.
    Prescription invalidDate(
        3, 10, 20,
        "Example medication",
        "As directed",
        "As directed",
        "01-01-2026",
        "2026-01-07");

    assert(!service.createPrescription(invalidDate));

    // Cancel an active prescription.
    assert(service.cancelPrescription(1));
    assert(service.findPrescriptionById(1)->getStatus() == "Cancelled");

    // A cancelled prescription cannot be completed.
    assert(!service.completePrescription(1));

    // Create and complete another prescription.
    Prescription second(
        2, 10, 20,
        "Example medication",
        "As directed",
        "As directed",
        "2026-01-01",
        "2026-01-07");

    assert(service.createPrescription(second));
    assert(service.completePrescription(2));
    assert(service.findPrescriptionById(2)->getStatus() == "Completed");

    // Reject invalid IDs and remove a prescription.
    assert(service.findPrescriptionById(-1) == nullptr);
    assert(!service.cancelPrescription(99));
    assert(service.removePrescription(2));
    assert(service.findPrescriptionById(2) == nullptr);
    assert(!service.removePrescription(2));

    std::cout << "Prescription service tests passed.\n";
    return 0;
}

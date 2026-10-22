
#include "models/Prescription.h"

#include <cassert>
#include <iostream>

int main()
{
    Prescription prescription(
        1, 10, 20,
        "Example medication",
        "As directed",
        "As directed",
        "2026-01-01",
        "2026-01-07");

    assert(prescription.getId() == 1);
    assert(prescription.getPatientId() == 10);
    assert(prescription.getDoctorId() == 20);

    assert(prescription.getMedicationName() == "Example medication");
    assert(prescription.getDosage() == "As directed");
    assert(prescription.getFrequency() == "As directed");
    assert(prescription.getStartDate() == "2026-01-01");
    assert(prescription.getEndDate() == "2026-01-07");
    assert(prescription.getStatus() == "Active");

    prescription.setStatus("Completed");
    prescription.setDosage("Updated instructions");

    assert(prescription.getStatus() == "Completed");
    assert(prescription.getDosage() == "Updated instructions");

    std::cout << "Prescription model tests passed.\n";
    return 0;
}

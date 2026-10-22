#include <cassert>
#include <iostream>

#include "models/MedicalRecord.h"

void testMedicalRecordConstructorAndGetters()
{
    MedicalRecord record(
        1,
        101,
        201,
        "Malaria",
        "Fever and headache",
        "Prescribed treatment",
        "2026-10-22");

    assert(record.getId() == 1);
    assert(record.getPatientId() == 101);
    assert(record.getDoctorId() == 201);
    assert(record.getDiagnosis() == "Malaria");
    assert(record.getSymptoms() == "Fever and headache");
    assert(record.getTreatment() == "Prescribed treatment");
    assert(record.getRecordDate() == "2026-10-22");

    std::cout << "testMedicalRecordConstructorAndGetters passed\n";
}

void testMedicalRecordSetters()
{
    MedicalRecord record(
        1,
        101,
        201,
        "Malaria",
        "Fever",
        "Initial treatment",
        "2026-10-22");

    record.setDiagnosis("Typhoid");
    record.setSymptoms("Fever and stomach pain");
    record.setTreatment("Updated treatment");

    assert(record.getDiagnosis() == "Typhoid");
    assert(record.getSymptoms() == "Fever and stomach pain");
    assert(record.getTreatment() == "Updated treatment");

    std::cout << "testMedicalRecordSetters passed\n";
}

int main()
{
    testMedicalRecordConstructorAndGetters();
    testMedicalRecordSetters();

    std::cout << "\nAll MedicalRecord model tests passed!\n";
    return 0;
}
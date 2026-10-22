#include <cassert>
#include <iostream>

#include "services/MedicalRecordService.h"

void testCreateRecord()
{
    MedicalRecordRepository repository;
    MedicalRecordService service(repository);

    MedicalRecord record(
        1, 101, 201,
        "Malaria", "Fever and headache",
        "Prescribed treatment", "2026-10-22");

    assert(service.createRecord(record));
    assert(service.findRecordById(1) != nullptr);
    assert(service.getAllRecords().size() == 1);

    std::cout << "testCreateRecord passed\n";
}

void testRejectInvalidRecord()
{
    MedicalRecordRepository repository;
    MedicalRecordService service(repository);

    MedicalRecord invalidRecord(
        0, 101, 201,
        "Malaria", "Fever",
        "Prescribed treatment", "2026-10-22");

    assert(!service.createRecord(invalidRecord));
    assert(service.getAllRecords().empty());

    std::cout << "testRejectInvalidRecord passed\n";
}

void testGetPatientMedicalHistory()
{
    MedicalRecordRepository repository;
    MedicalRecordService service(repository);

    MedicalRecord first(
        1, 101, 201,
        "Malaria", "Fever",
        "Treatment A", "2026-10-21");

    MedicalRecord second(
        2, 101, 201,
        "Flu", "Cough",
        "Treatment B", "2026-10-22");

    MedicalRecord third(
        3, 102, 202,
        "Allergy", "Sneezing",
        "Treatment C", "2026-10-23");

    assert(service.createRecord(first));
    assert(service.createRecord(second));
    assert(service.createRecord(third));

    auto history = service.getPatientMedicalHistory(101);

    assert(history.size() == 2);
    assert(history[0].getId() == 1);
    assert(history[1].getId() == 2);

    assert(service.getPatientMedicalHistory(-1).empty());

    std::cout << "testGetPatientMedicalHistory passed\n";
}

void testUpdateRecord()
{
    MedicalRecordRepository repository;
    MedicalRecordService service(repository);

    MedicalRecord original(
        1, 101, 201,
        "Malaria", "Fever",
        "Treatment A", "2026-10-22");

    MedicalRecord updated(
        1, 101, 201,
        "Typhoid", "Fever and stomach pain",
        "Treatment B", "2026-10-22");

    assert(service.createRecord(original));
    assert(service.updateRecord(updated));
    assert(service.findRecordById(1)->getDiagnosis() == "Typhoid");

    MedicalRecord missing(
        99, 101, 201,
        "Flu", "Cough",
        "Treatment C", "2026-10-22");

    assert(!service.updateRecord(missing));

    std::cout << "testUpdateRecord passed\n";
}

void testRemoveRecord()
{
    MedicalRecordRepository repository;
    MedicalRecordService service(repository);

    MedicalRecord record(
        1, 101, 201,
        "Malaria", "Fever",
        "Treatment A", "2026-10-22");

    assert(service.createRecord(record));
    assert(service.removeRecord(1));
    assert(service.findRecordById(1) == nullptr);
    assert(!service.removeRecord(-1));

    std::cout << "testRemoveRecord passed\n";
}

int main()
{
    testCreateRecord();
    testRejectInvalidRecord();
    testGetPatientMedicalHistory();
    testUpdateRecord();
    testRemoveRecord();

    std::cout << "\nAll MedicalRecord service tests passed!\n";
    return 0;
}
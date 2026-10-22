#include <cassert>
#include <iostream>

#include "repositories/MedicalRecordRepository.h"

void testAddAndFindRecord()
{
    MedicalRecordRepository repository;

    MedicalRecord record(
        1, 101, 201,
        "Malaria", "Fever", "Treatment A", "2026-10-22");

    assert(repository.add(record));
    assert(repository.findById(1) != nullptr);
    assert(repository.findById(1)->getPatientId() == 101);

    std::cout << "testAddAndFindRecord passed\n";
}

void testRejectDuplicateId()
{
    MedicalRecordRepository repository;

    MedicalRecord first(
        1, 101, 201,
        "Malaria", "Fever", "Treatment A", "2026-10-22");

    MedicalRecord duplicate(
        1, 102, 202,
        "Flu", "Cough", "Treatment B", "2026-10-22");

    assert(repository.add(first));
    assert(!repository.add(duplicate));
    assert(repository.getAll().size() == 1);

    std::cout << "testRejectDuplicateId passed\n";
}

void testFindByPatientId()
{
    MedicalRecordRepository repository;

    MedicalRecord first(
        1, 101, 201,
        "Malaria", "Fever", "Treatment A", "2026-10-22");

    MedicalRecord second(
        2, 101, 201,
        "Flu", "Cough", "Treatment B", "2026-10-23");

    MedicalRecord third(
        3, 102, 202,
        "Allergy", "Sneezing", "Treatment C", "2026-10-24");

    assert(repository.add(first));
    assert(repository.add(second));
    assert(repository.add(third));

    auto patientRecords = repository.findByPatientId(101);

    assert(patientRecords.size() == 2);
    assert(patientRecords[0].getId() == 1);
    assert(patientRecords[1].getId() == 2);

    std::cout << "testFindByPatientId passed\n";
}

void testUpdateRecord()
{
    MedicalRecordRepository repository;

    MedicalRecord original(
        1, 101, 201,
        "Malaria", "Fever", "Treatment A", "2026-10-22");

    MedicalRecord updated(
        1, 101, 201,
        "Typhoid", "Fever and pain", "Treatment B", "2026-10-22");

    assert(repository.add(original));
    assert(repository.update(updated));
    assert(repository.findById(1)->getDiagnosis() == "Typhoid");
    assert(repository.findById(1)->getTreatment() == "Treatment B");

    std::cout << "testUpdateRecord passed\n";
}

void testRemoveRecord()
{
    MedicalRecordRepository repository;

    MedicalRecord record(
        1, 101, 201,
        "Malaria", "Fever", "Treatment A", "2026-10-22");

    assert(repository.add(record));
    assert(repository.remove(1));
    assert(repository.findById(1) == nullptr);
    assert(!repository.remove(1));

    std::cout << "testRemoveRecord passed\n";
}

int main()
{
    testAddAndFindRecord();
    testRejectDuplicateId();
    testFindByPatientId();
    testUpdateRecord();
    testRemoveRecord();

    std::cout << "\nAll MedicalRecord repository tests passed!\n";
    return 0;
}
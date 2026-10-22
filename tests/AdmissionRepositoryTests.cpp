#include <cassert>
#include <iostream>

#include "repositories/AdmissionRepository.h"

void testAddAndFindAdmission()
{
    AdmissionRepository repository;

    Admission admission(
        1, 101, "Medical", "B12",
        "2026-10-21", "", "Admitted");

    assert(repository.add(admission));
    assert(repository.findById(1) != nullptr);
    assert(repository.findById(1)->getPatientId() == 101);

    std::cout << "testAddAndFindAdmission passed\n";
}

void testRejectDuplicateId()
{
    AdmissionRepository repository;

    Admission first(
        1, 101, "Medical", "B12",
        "2026-10-21", "", "Admitted");

    Admission duplicate(
        1, 102, "Surgical", "C05",
        "2026-10-22", "", "Admitted");

    assert(repository.add(first));
    assert(!repository.add(duplicate));
    assert(repository.getAll().size() == 1);

    std::cout << "testRejectDuplicateId passed\n";
}

void testUpdateAdmission()
{
    AdmissionRepository repository;

    Admission original(
        1, 101, "Medical", "B12",
        "2026-10-21", "", "Admitted");

    Admission updated(
        1, 101, "Surgical", "C05",
        "2026-10-21", "", "Admitted");

    assert(repository.add(original));
    assert(repository.update(updated));
    assert(repository.findById(1)->getWard() == "Surgical");
    assert(repository.findById(1)->getBedNumber() == "C05");

    std::cout << "testUpdateAdmission passed\n";
}

void testRemoveAdmission()
{
    AdmissionRepository repository;

    Admission admission(
        1, 101, "Medical", "B12",
        "2026-10-21", "", "Admitted");

    assert(repository.add(admission));
    assert(repository.remove(1));
    assert(repository.findById(1) == nullptr);
    assert(!repository.remove(1));

    std::cout << "testRemoveAdmission passed\n";
}

int main()
{
    testAddAndFindAdmission();
    testRejectDuplicateId();
    testUpdateAdmission();
    testRemoveAdmission();

    std::cout << "\nAll Admission repository tests passed!\n";
    return 0;
}
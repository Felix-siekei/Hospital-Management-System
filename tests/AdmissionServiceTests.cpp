#include <cassert>
#include <iostream>

#include "services/AdmissionService.h"

void testAdmitPatient()
{
    AdmissionRepository repository;
    AdmissionService service(repository);

    Admission admission(
        1, 101, "Medical", "B12",
        "2026-10-21", "", "Admitted");

    assert(service.admitPatient(admission));
    assert(service.findAdmissionById(1) != nullptr);
    assert(service.getAllAdmissions().size() == 1);

    std::cout << "testAdmitPatient passed\n";
}

void testRejectInvalidAdmission()
{
    AdmissionRepository repository;
    AdmissionService service(repository);

    Admission invalidAdmission(
        0, 101, "Medical", "B12",
        "2026-10-21", "", "Admitted");

    assert(!service.admitPatient(invalidAdmission));
    assert(service.getAllAdmissions().empty());

    std::cout << "testRejectInvalidAdmission passed\n";
}

void testDischargePatient()
{
    AdmissionRepository repository;
    AdmissionService service(repository);

    Admission admission(
        1, 101, "Medical", "B12",
        "2026-10-21", "", "Admitted");

    assert(service.admitPatient(admission));
    assert(service.dischargePatient(1, "2026-10-23"));

    Admission *discharged = service.findAdmissionById(1);
    assert(discharged != nullptr);
    assert(discharged->getStatus() == "Discharged");
    assert(discharged->getDischargeDate() == "2026-10-23");

    std::cout << "testDischargePatient passed\n";
}

void testRejectInvalidDischarge()
{
    AdmissionRepository repository;
    AdmissionService service(repository);

    Admission admission(
        1, 101, "Medical", "B12",
        "2026-10-21", "", "Admitted");

    assert(service.admitPatient(admission));

    // Discharge date is before admission date.
    assert(!service.dischargePatient(1, "2026-10-20"));

    // Admission does not exist.
    assert(!service.dischargePatient(99, "2026-10-23"));

    // Invalid admission ID.
    assert(!service.dischargePatient(-1, "2026-10-23"));

    std::cout << "testRejectInvalidDischarge passed\n";
}

void testRemoveAdmission()
{
    AdmissionRepository repository;
    AdmissionService service(repository);

    Admission admission(
        1, 101, "Medical", "B12",
        "2026-10-21", "", "Admitted");

    assert(service.admitPatient(admission));
    assert(service.removeAdmission(1));
    assert(service.findAdmissionById(1) == nullptr);

    std::cout << "testRemoveAdmission passed\n";
}

int main()
{
    testAdmitPatient();
    testRejectInvalidAdmission();
    testDischargePatient();
    testRejectInvalidDischarge();
    testRemoveAdmission();

    std::cout << "\nAll Admission service tests passed!\n";
    return 0;
}
#include <cassert>
#include <iostream>

#include "models/Patient.h"
#include "repositories/ PatientRepository.h"
#include "services/PatientService.h"

void testRegisterPatient() {

    PatientRepository repository;
    PatientService service(repository);

    Patient patient(
        1,
        "John",
        "Doe",
        25,
        "0712345678"
    );

    bool result = service.registerPatient(patient);

    assert(result == true);
    assert(repository.getAll().size() == 1);

    std::cout << "testRegisterPatient: PASSED\n";
}

void testFindPatient() {

    PatientRepository repository;
    PatientService service(repository);

    Patient patient(
        1,
        "gislo",
        "Doe",
        25,
        "0712345678"
    );

    service.registerPatient(patient);

    const Patient* found = service.findPatientById(1);

    assert(found != nullptr);
    assert(found->getFirstName() == "gislo");

    std::cout << "testFindPatient: PASSED\n";
}

void testInvalidPatient() {

    PatientRepository repository;
    PatientService service(repository);

    Patient invalidPatient(
        2,
        "Invalid",
        "Patient",
        -5,
        "0700000000"
    );

    bool result = service.registerPatient(invalidPatient);

    assert(result == false);
    assert(repository.getAll().empty());

    std::cout << "testInvalidPatient: PASSED\n";
}

void testUpdatePatient() {

    PatientRepository repository;

    Patient patient(
        1,
        "John",
        "Doe",
        25,
        "0712345678"
    );

    repository.add(patient);

    Patient updatedPatient(
        1,
        "Johnny",
        "Doe",
        26,
        "0799999999"
    );

    bool result = repository.update(updatedPatient);

    assert(result == true);

    const Patient* found = repository.findById(1);

    assert(found != nullptr);
    assert(found->getFirstName() == "Johnny");
    assert(found->getAge() == 26);
    assert(found->getPhone() == "0799999999");

    std::cout << "testUpdatePatient: PASSED\n";
}

void testRemovePatient() {

    PatientRepository repository;

    Patient patient(
        1,
        "John",
        "Doe",
        25,
        "0712345678"
    );

    repository.add(patient);

    bool result = repository.remove(1);

    assert(result == true);
    assert(repository.findById(1) == nullptr);

    std::cout << "testRemovePatient: PASSED\n";
}

int main() {

    testRegisterPatient();
    testFindPatient();
    testInvalidPatient();
    testUpdatePatient();
    testRemovePatient();

    std::cout << "\nAll tests passed!\n";

    return 0;
}
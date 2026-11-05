
#include <cassert>
#include <iostream>

#include "models/Patient.h"
#include "database/Database.h"
#include "repositories/PatientRepository.h"
#include "services/PatientService.h"


void testRegisterPatient() {

    Database database(":memory:");
    PatientRepository repository(database);
    PatientService service(repository);

    Patient patient(
        "John",
        "Doe",
        25,
        "0712345678"
    );
    auto before = repository.getAll();

std::cout << "Patients before registration: "
          << before.size() << '\n';

    bool result = service.registerPatient(patient);

std::cout << "Registration result: " << result << '\n';
std::cout << "Generated patient ID: " << patient.getId() << '\n';

auto patients = repository.getAll();

std::cout << "Patients found: " << patients.size() << '\n';

assert(result == true);
assert(patient.getId() > 0);
assert(patients.size() == 1);
}


void testFindPatient() {

    Database database(":memory:");
    PatientRepository repository(database);
    PatientService service(repository);

    Patient patient(
        "Gislo",
        "Doe",
        25,
        "0712345678"
    );

    service.registerPatient(patient);

    auto found = service.findPatientById(patient.getId());

    assert(found.has_value());
    assert(found->getFirstName() == "Gislo");

    std::cout << "testFindPatient: PASSED\n";
}


void testInvalidPatient() {

    Database database(":memory:");
    PatientRepository repository(database);
    PatientService service(repository);

    Patient invalidPatient(
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

    Database database(":memory:");
    PatientRepository repository(database);

    Patient patient(
        "John",
        "Doe",
        25,
        "0712345678"
    );

    repository.add(patient);

    Patient updatedPatient(
        "Johnny",
        "Doe",
        26,
        "0799999999"
    );

    updatedPatient.setId(patient.getId());

    bool result = repository.update(updatedPatient);

    assert(result == true);

    auto found = repository.findById(patient.getId());

    assert(found.has_value());
    assert(found->getFirstName() == "Johnny");
    assert(found->getAge() == 26);
    assert(found->getPhone() == "0799999999");

    std::cout << "testUpdatePatient: PASSED\n";
}


void testRemovePatient() {

    Database database(":memory:");
    PatientRepository repository(database);

    Patient patient(
        "John",
        "Doe",
        25,
        "0712345678"
    );

    repository.add(patient);

    bool result = repository.remove(patient.getId());

    assert(result == true);
    assert(!repository.findById(patient.getId()).has_value());

    // Test removing a patient that does not exist.
    assert(repository.remove(999) == false);

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

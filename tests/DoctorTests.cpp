
#include <cassert>
#include <iostream>

#include "models/Doctor.h"
#include "database/Database.h"
#include "repositories/DoctorRepository.h"
#include "services/DoctorService.h"

void testRegisterDoctor() {

    Database database(":memory:");
    DoctorRepository repository(database);
    DoctorService service(repository);

    Doctor doctor(
        "Sarah",
        "Mwangi",
        "Cardiology",
        "0712345678"
    );

    bool result = service.registerDoctor(doctor);

    assert(result == true);
    assert(doctor.getId() > 0);
    assert(repository.getAll().size() == 1);

    std::cout << "testRegisterDoctor: PASSED\n";
}

void testFindDoctor() {

    Database database(":memory:");
    DoctorRepository repository(database);
    DoctorService service(repository);

    Doctor doctor(
        "Sarah",
        "Mwangi",
        "Cardiology",
        "0712345678"
    );

    service.registerDoctor(doctor);

    auto found = service.findDoctorById(doctor.getId());

    assert(found.has_value());
    assert(found->getFirstName() == "Sarah");
    assert(found->getSpecialization() == "Cardiology");

    std::cout << "testFindDoctor: PASSED\n";
}

void testInvalidDoctor() {

    Database database(":memory:");
    DoctorRepository repository(database);
    DoctorService service(repository);

    Doctor doctor(
        "John",
        "Doe",
        "",
        "0700000000"
    );

    bool result = service.registerDoctor(doctor);

    assert(result == false);
    assert(repository.getAll().empty());

    std::cout << "testInvalidDoctor: PASSED\n";
}

void testUpdateDoctor() {

    Database database(":memory:");
    DoctorRepository repository(database);

    Doctor doctor(
        "Sarah",
        "Mwangi",
        "Cardiology",
        "0712345678"
    );

    repository.add(doctor);

    Doctor updatedDoctor(
        "Sarah",
        "Mwangi",
        "Neurology",
        "0799999999"
    );

    updatedDoctor.setId(doctor.getId());

    bool result = repository.update(updatedDoctor);

    assert(result == true);

    auto found = repository.findById(doctor.getId());

    assert(found.has_value());
    assert(found->getSpecialization() == "Neurology");
    assert(found->getPhone() == "0799999999");

    std::cout << "testUpdateDoctor: PASSED\n";
}

void testRemoveDoctor() {

    Database database(":memory:");
    DoctorRepository repository(database);

    Doctor doctor(
        "Sarah",
        "Mwangi",
        "Cardiology",
        "0712345678"
    );

    repository.add(doctor);

    bool result = repository.remove(doctor.getId());

    assert(result == true);
    assert(!repository.findById(doctor.getId()).has_value());

    std::cout << "testRemoveDoctor: PASSED\n";
}

int main() {

    testRegisterDoctor();
    testFindDoctor();
    testInvalidDoctor();
    testUpdateDoctor();
    testRemoveDoctor();

    std::cout << "\nAll doctor tests passed!\n";

    return 0;
}

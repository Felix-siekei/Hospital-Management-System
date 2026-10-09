#include <cassert>
#include <iostream>

#include "models/Doctor.h"
#include "repositories/DoctorRepository.h"
#include "services/DoctorService.h"

void testRegisterDoctor() {

    DoctorRepository repository;
    DoctorService service(repository);

    Doctor doctor(
        101,
        "Sarah",
        "Mwangi",
        "Cardiology",
        "0712345678"
    );

    bool result = service.registerDoctor(doctor);

    assert(result == true);
    assert(repository.getAll().size() == 1);

    std::cout << "testRegisterDoctor: PASSED\n";
}

void testFindDoctor() {

    DoctorRepository repository;
    DoctorService service(repository);

    Doctor doctor(
        101,
        "Sarah",
        "Mwangi",
        "Cardiology",
        "0712345678"
    );

    service.registerDoctor(doctor);

    const Doctor* found = service.findDoctorById(101);

    assert(found != nullptr);
    assert(found->getFirstName() == "Sarah");
    assert(found->getSpecialization() == "Cardiology");

    std::cout << "testFindDoctor: PASSED\n";
}

void testInvalidDoctor() {

    DoctorRepository repository;
    DoctorService service(repository);

    Doctor invalidDoctor(
        -1,
        "Invalid",
        "Doctor",
        "Cardiology",
        "0700000000"
    );

    bool result = service.registerDoctor(invalidDoctor);

    assert(result == false);
    assert(repository.getAll().empty());

    std::cout << "testInvalidDoctor: PASSED\n";
}

void testMissingSpecialization() {

    DoctorRepository repository;
    DoctorService service(repository);

    Doctor invalidDoctor(
        102,
        "John",
        "Doe",
        "",
        "0700000000"
    );

    bool result = service.registerDoctor(invalidDoctor);

    assert(result == false);
    assert(repository.getAll().empty());

    std::cout << "testMissingSpecialization: PASSED\n";
}

void testUpdateDoctor() {

    DoctorRepository repository;

    Doctor doctor(
        101,
        "Sarah",
        "Mwangi",
        "Cardiology",
        "0712345678"
    );

    repository.add(doctor);

    Doctor updatedDoctor(
        101,
        "Sarah",
        "Mwangi",
        "Neurology",
        "0799999999"
    );

    bool result = repository.update(updatedDoctor);

    assert(result == true);

    const Doctor* found = repository.findById(101);

    assert(found != nullptr);
    assert(found->getSpecialization() == "Neurology");
    assert(found->getPhone() == "0799999999");

    std::cout << "testUpdateDoctor: PASSED\n";
}

void testRemoveDoctor() {

    DoctorRepository repository;

    Doctor doctor(
        101,
        "Sarah",
        "Mwangi",
        "Cardiology",
        "0712345678"
    );

    repository.add(doctor);

    bool result = repository.remove(101);

    assert(result == true);
    assert(repository.findById(101) == nullptr);

    std::cout << "testRemoveDoctor: PASSED\n";
}

int main() {

    testRegisterDoctor();
    testFindDoctor();
    testInvalidDoctor();
    testMissingSpecialization();
    testUpdateDoctor();
    testRemoveDoctor();

    std::cout << "\nAll doctor tests passed!\n";

    return 0;
}
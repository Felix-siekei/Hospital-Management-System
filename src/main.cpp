#include <iostream>

#include "database/Database.h"
#include "repositories/PatientRepository.h"
#include "repositories/DoctorRepository.h"

int main() {

    Database database("hospital.db");

    PatientRepository patientRepository(database);
    DoctorRepository doctorRepository(database);

    // Sample patient
    Patient patient("Felix", "Siekei", 25, "0712345678");

    if (patientRepository.add(patient)) {
        std::cout << "Patient registered successfully. ID: "
                  << patient.getId() << std::endl;
    } else {
        std::cout << "Patient registration failed.\n";
    }

    // Sample doctor
    Doctor doctor("Sarah", "Mwangi", "Cardiology", "0798765432");

    if (doctorRepository.add(doctor)) {
        std::cout << "Doctor registered successfully. ID: "
                  << doctor.getId() << std::endl;
    } else {
        std::cout << "Doctor registration failed.\n";
    }


    // Retrieve all doctors
 std::cout << "\n--- Registered Doctors ---\n";

    for ( const Doctor& d: doctorRepository.getAll()){
        std::cout << "ID: "<< d.getId() << " | Name: "<< d.getFirstName()
        <<" " << d.getLastName()
        <<"| Specialization: "<< d.getSpecialization()
        <<std::endl;
    }

    return 0;

}
#include <iostream>
#include "models/Patient.h"
#include <vector>
#include "repositories/ PatientRepository.h"

int main(){

    std::cout<<"====================================\n";

    std::cout << "Hospital Management System" << std::endl;

    std::cout<<"====================================\n";





    PatientRepository repository;


    



    Patient patient1(1,"felix","Bikeri",20,"0788888888");

    Patient patient2(2,"John","Doe",30,"0788888889");

    repository.add(patient1);
    repository.add(patient2);

    //gett all patients

    const std::vector<Patient>& patients = repository.getAll();

    for (const auto& patient : patients){
        std::cout <<"ID: "<< patient.getId()
        <<" | Name: " <<patient.getFirstName() 
        <<" " << patient.getLastName()
        << " |  Age: "<< patient.getAge()
        <<'\n';

    };




 //updated patient


    Patient  updatePatient(
        2,
        "merry",
        "smith",
        33,
        "0757234264"
    );

    bool updated = repository.update(updatePatient);

    

    if (updated) {
    std::cout << "Patient updated successfully\n";
    } else {
    std::cout << "Patient not found\n";
    }




    //findbyID

    const Patient* foundPatient = repository.findById(2);
    
    if (foundPatient != nullptr) {
    std::cout << "Updated patient: "
              << foundPatient->getFirstName() << " "
              << foundPatient->getLastName()
              << " | Age: " << foundPatient->getAge()
              << " | Phone: " << foundPatient->getPhone()
              << '\n';


    }



   



    // std::cout<<"number of patients: "<<patients.size()<<'\n';







    return 0;
}
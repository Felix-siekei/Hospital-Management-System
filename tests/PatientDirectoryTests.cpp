#include <cassert>
#include <iostream>
#include <vector>
#include "models/Patient.h"
#include "services/PatientDirectory.h"
int main(){


    std::vector<Patient> patients = {
    Patient(1, "John", "Kamau", 25, "0712345678"),
    Patient(2, "Jane", "Wanjiku", 30, "0723456789"),
    Patient(3, "Peter", "Otieno", 28, "0734567890")
};


    PatientDirectory directory;

    std::vector<Patient> results = directory.findByFirstLetter(patients, 'J');

    assert(results.size()== 2);
    assert(results[0].getFirstName() == "John");
    assert(results[1].getFirstName() =="Jane");

    std::cout<<"PatientDirectory tests passed.\n";


   

}
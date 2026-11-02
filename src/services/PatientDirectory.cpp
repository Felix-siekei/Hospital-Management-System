#include "services/PatientDirectory.h"


std::vector<Patient> PatientDirectory::findByFirstLetter(const std::vector<Patient>& patients, char letter){



    std::vector<Patient>  results;

    for(const auto& patient: patients){
        if(!patient.getFirstName().empty() &&
            patient.getFirstName()[0]== letter){
            results.push_back(patient);
        }
    }
    return results;

}
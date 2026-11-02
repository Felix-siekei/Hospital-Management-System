#pragma once
#include "models/Patient.h"
#include <vector>
#include <string>


class PatientDirectory{
    public:
        std::vector<Patient>  findByFirstLetter(const std::vector<Patient>& patients, char letter);
};
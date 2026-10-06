#pragma once

#include <vector>
#include "models/Patient.h"

class PatientRepository{
    private:
        std::vector<Patient> patients;

    public:
        void add(const Patient& patient);

        const std::vector<Patient>& getAll() const;


        const Patient* findById(int id) const;

        bool update(const Patient& updatedPatient);


        bool remove(int id);

   
};




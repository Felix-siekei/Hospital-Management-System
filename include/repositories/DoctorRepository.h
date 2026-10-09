#pragma once

#include <vector>
#include "models/Doctor.h"

class DoctorRepository{
    private:
        std::vector<Doctor> doctors;

    public:
        void add(const Doctor& doctor);
        const std::vector<Doctor>& getAll() const;

        const Doctor* findById(int id) const;

        bool update(const Doctor& updateDoctor);

        bool remove( int id);

};
#pragma once

#include <vector>
#include <optional>

#include "models/Doctor.h"
#include "database/Database.h"


class DoctorRepository{

    private:

        Database& database;


        
    public:
        explicit DoctorRepository(Database& database);

       bool add( Doctor& doctor);

        std::vector<Doctor> getAll() const;

        std::optional<Doctor> findById(int id) const;

        bool update(const Doctor& updateDoctor);

        bool remove( int id);

};
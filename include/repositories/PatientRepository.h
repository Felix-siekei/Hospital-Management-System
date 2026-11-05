
#pragma once

#include <vector>
#include <optional>

#include "models/Patient.h"
#include "database/Database.h"

class PatientRepository {
private:
    Database& database;

public:
    explicit PatientRepository(Database& database);

    bool add(Patient& patient);

    std::vector<Patient> getAll() const;

    std::optional<Patient> findById(int id) const;

    bool update(const Patient& updatedPatient);

    bool remove(int id);
};

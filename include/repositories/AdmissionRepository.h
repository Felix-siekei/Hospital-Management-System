#pragma once
#include <vector>
#include "models/Admission.h"

class AdmissionRepository{
    private:
        std::vector<Admission> admissions;

    public:
        bool add(const Admission &admission);
        Admission* findById(int id);
        std::vector<Admission> getAll()const;
        bool update(const Admission &admission);
        bool remove(int id);
};
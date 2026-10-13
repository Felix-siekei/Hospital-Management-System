#pragma once
#include <vector>
#include "models/Department.h"

class DepartmentRepository{
    private:
        std::vector<Department> departments;

    public:
        bool add(const Department& department);
        std::vector<Department> getAll() const;
        Department* findById( int id);
        bool update(const Department& department);
        bool remove(int id);
};
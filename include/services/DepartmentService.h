#pragma once

#include  "repositories/DepartmentRepository.h"

class DepartmentService{
    private:
        DepartmentRepository& repository;

    public:
        explicit DepartmentService(DepartmentRepository &repository);

        bool registerDepartment(const Department& department);
     
        bool updateDepartment(const Department& department);
        bool removeDepartment(int id);
};
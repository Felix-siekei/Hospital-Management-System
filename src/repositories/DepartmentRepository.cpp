#include "repositories/DepartmentRepository.h"


bool DepartmentRepository::add(const Department& department){
    if(findById(department.getId()) != nullptr){
        return false;
    }
    departments.push_back(department);
    return true;
}

std::vector<Department> DepartmentRepository::getAll() const{
    return departments;
}

Department* DepartmentRepository::findById(int id){
    for (auto& department: departments){
        if(department.getId() == id){
            return &department;
        }
    }
    return nullptr;
}


bool DepartmentRepository::update(const Department& department){
    Department *existing = findById(department.getId());

    if(existing == nullptr){
        return false;
    }

    existing->setName(department.getName());
    existing->setLocation(department.getLocation());
    existing->setDescription(department.getDescription());

    return true;
}

bool DepartmentRepository::remove(int id){
    for (auto it = departments.begin(); it != departments.end(); ++it)
    {
        if(it->getId() == id){
            departments.erase(it);
            return true;
        }
    }
    return false;
}
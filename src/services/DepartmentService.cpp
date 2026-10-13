#include "services/DepartmentService.h"

DepartmentService::DepartmentService(DepartmentRepository& repository):repository(repository){

}

bool DepartmentService::registerDepartment(const Department& department){
    if(department.getId() <= 0){
        return false;
    }
    if(department.getName().empty()){
        return false;
    }
    if (department.getLocation().empty())
    {
        return false;
    }
    return repository.add(department);
}
Department *DepartmentService::findDepartmentById(int id){
    if(id<=0){
        return nullptr;
    }
    return repository.findById(id);
}

bool DepartmentService::updateDepartment(const Department& department){
    if(department.getId() <=0 || department.getName().empty()||department.getLocation().empty()){
        return false;
    }

    return repository.update(department);
}
bool DepartmentService::removeDepartment(int id){
    if(id <=0 ){
        return false;
    }
    return repository.remove(id);
}
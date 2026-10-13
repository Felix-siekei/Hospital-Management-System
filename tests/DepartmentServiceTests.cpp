
#include <cassert>
#include <iostream>

#include "services/DepartmentService.h"

void testRegisterDepartment()
{
    DepartmentRepository repository;
    DepartmentService service(repository);

    Department department(1, "Cardiology", "Block A", "Heart care");

    assert(service.registerDepartment(department));
    assert(service.findDepartmentById(1) != nullptr);

    std::cout << "testRegisterDepartment passed\n";
}

void testInvalidDepartmentId()
{
    DepartmentRepository repository;
    DepartmentService service(repository);

    Department department(0, "Cardiology", "Block A", "Heart care");

    assert(!service.registerDepartment(department));
    assert(!service.removeDepartment(-1));

    std::cout << "testInvalidDepartmentId passed\n";
}

void testEmptyDepartmentName()
{
    DepartmentRepository repository;
    DepartmentService service(repository);

    Department department(1, "", "Block A", "Heart care");

    assert(!service.registerDepartment(department));

    std::cout << "testEmptyDepartmentName passed\n";
}

void testUpdateDepartment()
{
    DepartmentRepository repository;
    DepartmentService service(repository);

    Department original(1, "Cardiology", "Block A", "Heart care");
    Department updated(1, "Neurology", "Block B", "Nervous system care");

    assert(service.registerDepartment(original));
    assert(service.updateDepartment(updated));

    Department *found = service.findDepartmentById(1);

    assert(found != nullptr);
    assert(found->getName() == "Neurology");

    std::cout << "testUpdateDepartment passed\n";
}

void testRemoveDepartment()
{
    DepartmentRepository repository;
    DepartmentService service(repository);

    Department department(1, "Cardiology", "Block A", "Heart care");

    assert(service.registerDepartment(department));
    assert(service.removeDepartment(1));
    assert(service.findDepartmentById(1) == nullptr);

    std::cout << "testRemoveDepartment passed\n";
}

int main()
{
    testRegisterDepartment();
    testInvalidDepartmentId();
    testEmptyDepartmentName();
    testUpdateDepartment();
    testRemoveDepartment();

    std::cout << "\nAll Department Service tests passed!\n";

    return 0;
}

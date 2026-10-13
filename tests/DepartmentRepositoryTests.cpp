
#include <cassert>
#include <iostream>

#include "repositories/DepartmentRepository.h"

void testAddDepartment()
{
    DepartmentRepository repository;

    Department department(
        1, "Cardiology", "Block A", "Heart care");

    assert(repository.add(department));
    assert(repository.getAll().size() == 1);

    std::cout << "testAddDepartment passed\n";
}

void testRejectDuplicateId()
{
    DepartmentRepository repository;

    Department first(1, "Cardiology", "Block A", "Heart care");
    Department duplicate(1, "Neurology", "Block B", "Nervous system care");

    assert(repository.add(first));
    assert(!repository.add(duplicate));
    assert(repository.getAll().size() == 1);

    std::cout << "testRejectDuplicateId passed\n";
}

void testFindDepartment()
{
    DepartmentRepository repository;

    Department department(1, "Cardiology", "Block A", "Heart care");
    assert(repository.add(department));

    Department *found = repository.findById(1);

    assert(found != nullptr);
    assert(found->getName() == "Cardiology");
    assert(repository.findById(99) == nullptr);

    std::cout << "testFindDepartment passed\n";
}

void testUpdateDepartment()
{
    DepartmentRepository repository;

    Department original(1, "Cardiology", "Block A", "Heart care");
    Department updated(1, "Neurology", "Block B", "Nervous system care");

    assert(repository.add(original));
    assert(repository.update(updated));

    Department *found = repository.findById(1);

    assert(found != nullptr);
    assert(found->getName() == "Neurology");
    assert(found->getLocation() == "Block B");
    assert(found->getDescription() == "Nervous system care");

    Department missing(99, "Radiology", "Block C", "Imaging");
    assert(!repository.update(missing));

    std::cout << "testUpdateDepartment passed\n";
}

void testRemoveDepartment()
{
    DepartmentRepository repository;

    Department department(1, "Cardiology", "Block A", "Heart care");
    assert(repository.add(department));

    assert(repository.remove(1));
    assert(repository.findById(1) == nullptr);
    assert(repository.getAll().empty());
    assert(!repository.remove(99));

    std::cout << "testRemoveDepartment passed\n";
}

int main()
{
    testAddDepartment();
    testRejectDuplicateId();
    testFindDepartment();
    testUpdateDepartment();
    testRemoveDepartment();

    std::cout << "\nAll Department Repository tests passed!\n";

    return 0;
}

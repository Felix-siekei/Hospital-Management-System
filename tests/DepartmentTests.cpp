
#include <cassert>
#include <iostream>
#include <string>

#include "models/Department.h"

int main()
{
    Department department(
        1,
        "Cardiology",
        "Block A",
        "Heart and cardiovascular care");

    // Test the constructor and getters
    assert(department.getId() == 1);
    assert(department.getName() == "Cardiology");
    assert(department.getLocation() == "Block A");
    assert(department.getDescription() == "Heart and cardiovascular care");

    // Test updating department details
    department.setName("Neurology");
    department.setLocation("Block B");
    department.setDescription("Nervous system care");

    assert(department.getName() == "Neurology");
    assert(department.getLocation() == "Block B");
    assert(department.getDescription() == "Nervous system care");

    std::cout << "All Department tests passed!" << std::endl;

    return 0;
}

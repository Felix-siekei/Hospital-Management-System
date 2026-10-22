
#include <cassert>
#include <iostream>

#include "models/Admission.h"

void testAdmissionConstructorAndGetters()
{
    Admission admission(
        1,
        101,
        "Medical",
        "B12",
        "2026-10-21",
        "",
        "Admitted");

    assert(admission.getId() == 1);
    assert(admission.getPatientId() == 101);
    assert(admission.getWard() == "Medical");
    assert(admission.getBedNumber() == "B12");
    assert(admission.getAdmissionDate() == "2026-10-21");
    assert(admission.getDischargeDate().empty());
    assert(admission.getStatus() == "Admitted");

    std::cout << "testAdmissionConstructorAndGetters passed\n";
}

void testAdmissionSetters()
{
    Admission admission(
        1,
        101,
        "Medical",
        "B12",
        "2026-10-21",
        "",
        "Admitted");

    admission.setWard("Surgical");
    admission.setBedNumber("C05");
    admission.setDischargeDate("2026-10-25");
    admission.setStatus("Discharged");

    assert(admission.getWard() == "Surgical");
    assert(admission.getBedNumber() == "C05");
    assert(admission.getDischargeDate() == "2026-10-25");
    assert(admission.getStatus() == "Discharged");

    std::cout << "testAdmissionSetters passed\n";
}

int main()
{
    testAdmissionConstructorAndGetters();
    testAdmissionSetters();

    std::cout << "\nAll Admission model tests passed!\n";

    return 0;
}

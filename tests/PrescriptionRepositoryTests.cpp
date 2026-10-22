
#include "repositories/PrescriptionRepository.h"

#include <cassert>
#include <iostream>

int main() {
    PrescriptionRepository repository;

    Prescription prescription(
        1, 10, 20,
        "Example medication",
        "As directed",
        "As directed",
        "2026-01-01",
        "2026-01-07"
    );

    assert(repository.add(prescription));
    assert(!repository.add(prescription));

    assert(repository.findById(1) != nullptr);
    assert(repository.findById(99) == nullptr);

    assert(repository.getAll().size() == 1);
    assert(repository.findByPatientId(10).size() == 1);
    assert(repository.findByPatientId(99).empty());

    prescription.setStatus("Completed");

    assert(repository.update(prescription));
    assert(repository.findById(1)->getStatus() == "Completed");

    assert(!repository.update(Prescription(
        99, 10, 20,
        "Example medication",
        "As directed",
        "As directed",
        "2026-01-01",
        "2026-01-07"
    )));

    assert(repository.remove(1));
    assert(repository.findById(1) == nullptr);
    assert(!repository.remove(1));

    std::cout << "Prescription repository tests passed.\n";
    return 0;
}

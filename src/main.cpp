#include "database/Database.h"
#include "repositories/PatientRepository.h"

int main() {
    Database database("hospital.db");

    PatientRepository repository(database);

    return 0;
}
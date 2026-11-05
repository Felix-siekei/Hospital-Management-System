#include "repositories/PatientRepository.h"

#include <stdexcept>

// Constructor
PatientRepository::PatientRepository(Database& database)
    : database(database) {

    const char* createPatientsTable =
        "CREATE TABLE IF NOT EXISTS patients ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "first_name TEXT NOT NULL,"
        "last_name TEXT NOT NULL,"
        "age INTEGER,"
        "phone TEXT"
        ");";

    if (!database.execute(createPatientsTable)) {
        throw std::runtime_error("Failed to create patients table.");
    }
}

bool PatientRepository::add(Patient& patient) {

    sqlite3* db = database.getConnection();

    const char* sql =
        "INSERT INTO patients (first_name, last_name, age, phone) "
        "VALUES (?, ?, ?, ?);";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    if (
        sqlite3_bind_text(stmt, 1, patient.getFirstName().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 2, patient.getLastName().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK ||
        sqlite3_bind_int(stmt, 3, patient.getAge()) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 4, patient.getPhone().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK
    ) {
        sqlite3_finalize(stmt);
        return false;
    }

    int result = sqlite3_step(stmt);

    if (result != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_int64 id = sqlite3_last_insert_rowid(db);

    patient.setId(static_cast<int>(id));

    sqlite3_finalize(stmt);

    return true;
}

std::vector<Patient> PatientRepository::getAll() const {

    std::vector<Patient> patients;

    sqlite3* db = database.getConnection();

    const char* sql = "SELECT * FROM patients;";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return patients;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {

        int id = sqlite3_column_int(stmt, 0);

        const auto* firstNameText = sqlite3_column_text(stmt, 1);
        const auto* lastNameText = sqlite3_column_text(stmt, 2);
        const auto* phoneText = sqlite3_column_text(stmt, 4);

        std::string firstName = firstNameText
            ? reinterpret_cast<const char*>(firstNameText) : "";

        std::string lastName = lastNameText
            ? reinterpret_cast<const char*>(lastNameText) : "";

        int age = sqlite3_column_int(stmt, 3);

        std::string phone = phoneText
            ? reinterpret_cast<const char*>(phoneText) : "";

        Patient patient(firstName, lastName, age, phone);

        patient.setId(id);

        patients.push_back(patient);
    }

    sqlite3_finalize(stmt);

    return patients;
}

bool PatientRepository::update(const Patient& updatedPatient){
    sqlite3* db = database.getConnection();


    const char* sql =
        "UPDATE patients "
        "SET first_name = ?, last_name = ?, age = ?, phone = ? "
        "WHERE id = ?;";

    sqlite3_stmt* stmt = nullptr;

    //prepare the statement
    if(sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK){
        return false;

    }
    if (
    sqlite3_bind_text(stmt, 1, updatedPatient.getFirstName().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK ||
    sqlite3_bind_text(stmt, 2, updatedPatient.getLastName().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK ||
    sqlite3_bind_int(stmt, 3, updatedPatient.getAge()) != SQLITE_OK ||
    sqlite3_bind_text(stmt, 4, updatedPatient.getPhone().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK ||
    sqlite3_bind_int(stmt, 5, updatedPatient.getId()) != SQLITE_OK
) {
    sqlite3_finalize(stmt);
    return false;
}

int result = sqlite3_step(stmt);

sqlite3_finalize(stmt);

return result == SQLITE_DONE;
}



bool PatientRepository::remove(int id) {

    sqlite3* db = database.getConnection();

    const char* sql = "DELETE FROM patients WHERE id = ?;";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    if (sqlite3_bind_int(stmt, 1, id) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return false;
    }

    int result = sqlite3_step(stmt);

    if (result != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return false;
    }

    int changes = sqlite3_changes(db);

    sqlite3_finalize(stmt);

    return changes > 0;
}
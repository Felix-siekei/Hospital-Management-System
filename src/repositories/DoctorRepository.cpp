#include <sqlite3.h>
#include <iostream>
#include <stdexcept>
#include "repositories/DoctorRepository.h"

DoctorRepository::DoctorRepository(Database& database):database(database){

     const char* createDoctorsTable =
        "CREATE TABLE IF NOT EXISTS doctors ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "first_name TEXT NOT NULL,"
        "last_name TEXT NOT NULL,"
        "specialization TEXT NOT NULL,"
        "phone TEXT"
        ");";

    if (!database.execute(createDoctorsTable)) {
        throw std::runtime_error("Failed to create doctors table.");
    }



}


bool DoctorRepository::add(Doctor& doctor) {
    // getConnection first
    sqlite3* db = database.getConnection();

    const char* sql =
        "INSERT INTO doctors "
        "(first_name, last_name, specialization, phone) "
        "VALUES (?, ?, ?, ?);";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    if (
        sqlite3_bind_text(stmt, 1, doctor.getFirstName().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 2, doctor.getLastName().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 3, doctor.getSpecialization().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 4, doctor.getPhone().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK
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

    doctor.setId(static_cast<int>(id));

    sqlite3_finalize(stmt);

    return true;
}

std::vector<Doctor> DoctorRepository::getAll() const {

    std::vector<Doctor> doctors;

    sqlite3* db = database.getConnection();

    const char* sql = "SELECT * FROM doctors;";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return doctors;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {

        int id = sqlite3_column_int(stmt, 0);

        std::string firstName =
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

        std::string lastName =
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

        std::string specialization =
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

        std::string phone =
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

        Doctor doctor(firstName, lastName, specialization, phone);

        doctor.setId(id);

        doctors.push_back(doctor);
    }

    sqlite3_finalize(stmt);

    return doctors;
}


std::optional<Doctor> DoctorRepository::findById(int id) const {

    sqlite3* db = database.getConnection();

    const char* sql =
        "SELECT * FROM doctors WHERE id = ?;";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return std::nullopt;
    }

    if (sqlite3_bind_int(stmt, 1, id) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    }

    int result = sqlite3_step(stmt);

    if (result != SQLITE_ROW) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    }

    int doctorId = sqlite3_column_int(stmt, 0);

    std::string firstName =
        reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

    std::string lastName =
        reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

    std::string specialization =
        reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

    std::string phone =
        reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

    Doctor doctor(firstName, lastName, specialization, phone);

    doctor.setId(doctorId);

    sqlite3_finalize(stmt);

    return doctor;
}

bool DoctorRepository::update(const Doctor& updatedDoctor) {

    sqlite3* db = database.getConnection();

    const char* sql =
        "UPDATE doctors SET "
        "first_name = ?, "
        "last_name = ?, "
        "specialization = ?, "
        "phone = ? "
        "WHERE id = ?;";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    if (
        sqlite3_bind_text(stmt, 1, updatedDoctor.getFirstName().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 2, updatedDoctor.getLastName().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 3, updatedDoctor.getSpecialization().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 4, updatedDoctor.getPhone().c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK ||
        sqlite3_bind_int(stmt, 5, updatedDoctor.getId()) != SQLITE_OK
    ) {
        sqlite3_finalize(stmt);
        return false;
    }

    int result = sqlite3_step(stmt);

    bool success = result == SQLITE_DONE && sqlite3_changes(db) > 0;

    sqlite3_finalize(stmt);

    return success;
}

bool DoctorRepository::remove(int id) {

    sqlite3* db = database.getConnection();

    const char* sql =
        "DELETE FROM doctors WHERE id = ?;";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    if (sqlite3_bind_int(stmt, 1, id) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return false;
    }

    int result = sqlite3_step(stmt);

    bool success = result == SQLITE_DONE && sqlite3_changes(db) > 0;

    sqlite3_finalize(stmt);

    return success;
}
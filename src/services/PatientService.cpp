#include "services/PatientService.h"


PatientService::PatientService(PatientRepository& repository)
    : repository(repository) { 

    };

bool PatientService::registerPatient( Patient& patient){

    if( patient.getAge() < 0){
        return false;
    }
   
    return repository.add(patient);
};


std::optional<Patient> PatientRepository::findById(int id) const {

    sqlite3* db = database.getConnection();
    const char* sql = "SELECT * FROM patients WHERE id = ?;";
    
    sqlite3_stmt* stmt = nullptr;

    if(sqlite3_prepare_v2(db, sql,-1, &stmt, nullptr)!= SQLITE_OK){
        return std::nullopt ;
    }
    if(sqlite3_bind_int(stmt,1, id) != SQLITE_OK){
        sqlite3_finalize(stmt);
        return std::nullopt;
    }

    int result = sqlite3_step(stmt);
    
    if(result != SQLITE_ROW){
        sqlite3_finalize(stmt);
        return std::nullopt;
    }
    int patientId = sqlite3_column_int(stmt, 0);

    std::string firstName =
        reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

    std::string lastName =
        reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

    int age = sqlite3_column_int(stmt, 3);

    std::string phone =
        reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

    Patient patient(firstName,lastName,age,phone);
    patient.setId(patientId);

    sqlite3_finalize(stmt);
    return patient;

};




std::optional<Patient> PatientService::findPatientById(int id) const {
    return repository.findById(id);
}

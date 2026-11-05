#include "database/Database.h"
#include <iostream>

Database::Database(const char* filename){

    int result = sqlite3_open(filename, &db);

    if(result ==SQLITE_OK){
        std::cout << "Database opened successfully" << std::endl;
      
    } else{
    
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        if (db != nullptr) {
        sqlite3_close(db);
        db = nullptr;
    }
     
    }

};

Database::~Database(){
    if(db != nullptr){
         sqlite3_close(db);
    }
   
};

bool Database::execute(const char* sql){

    if (db == nullptr) {
    std::cerr << "Database connection is not available."
              << std::endl;
    return false;
  }

    int result = sqlite3_exec(db, sql, nullptr, nullptr, nullptr);

    if(result == SQLITE_OK){
        std::cout << "SQL statement executed successfully" << std::endl;
        return true;
    } else{
        std::cerr << "Error executing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    



   
};
sqlite3* Database::getConnection() const {
    return db;
}
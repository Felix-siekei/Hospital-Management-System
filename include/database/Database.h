#include <sqlite3.h>
#pragma once

class Database {
    private:

     sqlite3* db= nullptr;


    public:
        Database(const char* filename);
        ~Database();
        bool execute(const char* sql);

        //accessor
        sqlite3* getConnection() const;

};
#pragma once
#include <string>

class Department{
    private:
    
        int id;
        std::string name;
        std::string location;
        std::string description;

    public:
        Department(   
            int id,
            const std::string& name,
            const std::string& location,
            const std::string& description
        );

        //setter

        int getId() const ;

        const std::string &getName() const;

        const std::string& getLocation() const;

        const std::string& getDescription() const;

        //getter

        void setName(const std::string& name);
        void setLocation(const std::string& location);
        void setDescription(const std::string &description);
};

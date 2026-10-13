#include "models/Department.h"
#include <string>

Department::Department(
    int id,
    const std::string &name,
    const std::string &location,
    const std::string &description
    
    ):
    id(id),
    name(name),
    location(location),
    description(description){

    }


int Department::getId()  const{
    return id;
}

const std::string& Department::getName() const{
    return name;
}

const std::string& Department::getLocation() const{
    return location;
}
const std::string& Department::getDescription() const{
    return description;
}


//setters


void Department::setName( const std::string& name){
    this->name = name;
}

void Department::setLocation(const std::string& location){
    this->location = location;
}

void Department::setDescription(const std::string &description)
{
    this->description = description;
}

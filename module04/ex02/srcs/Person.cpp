#include "Person.hpp"

Person::Person(std::string p_name): _name(p_name), _currentRoom(nullptr) {
    std::cout << "Person " << p_name << " is created.\n";
}

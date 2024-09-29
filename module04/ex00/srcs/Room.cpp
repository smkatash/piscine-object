#include "Room.hpp"

Room::Room(): ID(uID++) {
    std::cout << "Room " << this->ID << " is created.\n";
}

bool    Room::canEnter(Person* p) {
    std::vector<Person*>::iterator it = this->_occupants.begin();
    for (; it != this->_occupants.end(); ++it) {
        Person* op = *it;
        if (op->get_name() == p->get_name()) {
            return (false);
        }
    }
    return (true);
}

void Room::enter(Person* p) {
    this->_occupants.push_back(p);
}

void Room::exit(Person* p) {
    std::vector<Person*>::iterator it = this->_occupants.begin();
    for (; it != this->_occupants.end(); ++it) {
       if (p == *it) {
            this->_occupants.erase(it);
            break;
       } 
    }
}

void    Room::printOccupant() {
    std::cout << "Occupants of Room " << this->ID << std::endl;
    std::vector<Person*>::iterator it = this->_occupants.begin();
    for (; it != this->_occupants.end(); ++it) {
       std::cout << (*it)->get_name() << std::endl;
    }
}


Classroom::Classroom(): Room() {
    std::cout << "Classroom " << " is created.\n";
}

void Classroom::assignCourse(Course* p_course) {
    this->_currentRoom = p_course;
}

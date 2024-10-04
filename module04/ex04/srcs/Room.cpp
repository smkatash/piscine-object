#include "Room.hpp"

long Room::uID = 1;

Room::Room(): ID(uID++) {
    std::cout << "Room " << this->ID << " is created.\n";
}

long	Room::get_id() { return this->ID;}

bool    Room::canEnter() {
    return this->_occupants.empty();
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

void Room::enter(Person* p) {
    std::vector<Person*>::iterator it = this->_occupants.begin();
    for (; it != this->_occupants.end(); ++it) {
       if (p == *it) {
            return;
       } 
    }
    this->_occupants.push_back(p);
}

void    Room::printOccupant() {
    std::cout << "Occupants of Room " << this->ID << ": ";
    if (this->_occupants.empty()) {
        std::cout << "empty.\n";
        return ;
    }
    std::vector<Person*>::iterator it = this->_occupants.begin();
    for (; it != this->_occupants.end(); ++it) {
       std::cout << (*it)->get_name() << ", ";
    }
    std::cout << std::endl;
}


Classroom::Classroom(): Room() {
    std::cout << "Classroom " << " is created.\n";
}

void Classroom::assignCourse(Course* p_course) {
    this->_currentRoom = p_course;
}
void Classroom::removeCourse() {
    this->_currentRoom = nullptr;
}

Course	*Classroom::getCurrentCourse() {
    return this->_currentRoom;
}

bool Classroom::canEnterClassroom() {
    return this->canEnter() && !this->_currentRoom;
}

#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <string>

class Room;

class Person {
protected:
	std::string _name;
	Room* _currentRoom;
public:
	Person(std::string p_name);
	Room* room() {return (_currentRoom);}
	const std::string& get_name() { return (_name);}
};

#endif

#pragma once

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
	virtual ~Person() {
		std::cout << this->_name << " is destroyed.\n";
	};
};


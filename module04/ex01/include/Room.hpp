#ifndef ROOM_HPP
#define ROOM_HPP
#include <iostream>
#include <vector>
#include "Person.hpp"

class Course;
class Form;


class Room {
private:
	long ID;
	std::vector<Person*> _occupants;
	static long uID;

public:
	Room();
	long	get_id();
	bool canEnter(Person* p);
	void enter(Person* p);
	void exit(Person* p);
	
	void printOccupant();
};

class HeadmasterOffice : public Room {
};

class StaffRestRoom : public Room {
};

class Courtyard : public Room {
};

class Classroom : public Room
{
private:
	Course* _currentRoom;

public:
	Classroom();
	void assignCourse(Course* p_course);
};

class SecretarialOffice: public Room
{
private:
	std::vector<Form*> _archivedForms;

public:

};

#endif

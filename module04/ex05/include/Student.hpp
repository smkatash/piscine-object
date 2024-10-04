#pragma once

#include "Person.hpp"
#include "Room.hpp"
#include "Form.hpp"
#include "Headmaster.hpp"
#include <map>

class Course;
class Headmaster;

class Student : public Person {
private:
	std::map<Course*, size_t> _subscribedCourse;
	void fillForm(Form* form, Course* course);

public:
	Student(std::string p_name);
	void attendClass(Course *p_course, Room* room);
	void enterClass(Room *room);
	void exitClass(Room* room);
	void graduate(Course* p_course);
	void subscribe(Course* p_course);
	void subscribeToNewCourse(Headmaster* headmaster, Course* p_course);
	void takeNotes();
	bool isSubscribed(Course* p_course);
	size_t numberOfAttendedClasses(Course* p_course);
};

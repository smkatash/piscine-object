#pragma once

#include "Staff.hpp"
#include "Course.hpp"
#include "Headmaster.hpp"
#include <vector>

class Headmaster;
class Student;

class Professor : public Staff {
private:
	Course*     	_currentCourse;
	void		fillForm(Form* form, Student* student, Course* course, Classroom *room);

public:
	Professor(std::string p_name);
	void	setCourse(Course* p_course);
	Course*	getCurrentCourse();
	void	doClass(Student* student);
	void	setClassroom(Room* room);
	void 	enterClass(Room *room);
	void 	exitClass(Room *room);
	void	closeCourse();
	void	assignNewCourse(Headmaster* headmaster, Course* course);
	void	assignNewClassroom(Headmaster* headmaster, Classroom *room);
	void	graduateStudent(Headmaster* headmaster, Student* student, Course* course);
};

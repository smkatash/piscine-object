#pragma once

#include "Staff.hpp"
#include "Course.hpp"
#include "Headmaster.hpp"
#include <vector>

class Headmaster;
class Student;

class Professor : public Staff {
private:
	Course*     _currentCourse;
	Classroom*     _currentRoom;
	void		fillForm(Form* form, Student* student, Course* course, Classroom *room);

public:
	Professor(std::string p_name);
	void	setCourse(Course* p_course);
	Course*	getCurrentCourse();
	void	setClassroom(Classroom* room);
	void	doClass(Student* student);
	void	closeCourse();
	void	assignNewCourse(Headmaster* headmaster, Course* course);
	void	assignNewClassroom(Headmaster* headmaster, Classroom *room);
	void	graduateStudent(Headmaster* headmaster, Student* student, Course* course);
};

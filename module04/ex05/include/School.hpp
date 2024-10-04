#pragma once

#include <vector>
#include "Course.hpp"
#include "Student.hpp"
#include "Observer.hpp"
#include "Professor.hpp"

class School{
private:
	std::vector<Course*>	_courses;
	std::vector<Observer*>	_observers;
	std::vector<Student*>	_students;
	std::vector<Professor*>	_professors;
	std::vector<Classroom*>	_rooms;
	Headmaster*			_headmaster;
	Secretary*			_secretary;
public:
	School();
	~School();

	Course*				getCourse(std::string name);
	std::vector<Course*>		getAllCourses();
	std::vector<Student*>		getStudents();
	std::vector<Observer*>		getObservers();
	std::vector<Classroom*>		getClassrooms();
	std::vector<Professor*>		getProfessors();
	Headmaster*					getHeadmaster();
	Secretary*					getSecretary();

	void	runDayRoutine();
	void	launchClasses();

	void	requestRingBell();
	void	addCourse(Course* course);
	void	addClassroom(Classroom* room);
	void	addObserver(Observer* observer);
	void	recruteProfessor(Professor* professor);
	void	recruteStudent(Student* student);
	void	graduationCeremony();
};

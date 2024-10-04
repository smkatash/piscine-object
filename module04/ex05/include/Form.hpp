#pragma once

#include "FormType.hpp"
#include "Course.hpp"
#include <iostream>

class Student;
class Course;
class Professor;

class Form {
protected:
	FormTypes::Type _formType;
	std::string		_filledData;
	Student*		_student;
	Course*			_course;	
	Classroom*		_room;	
	Professor*		_professor;	
	bool			_isSigned;

public:
	Form(FormTypes::Type p_formType);
	void	sign();
	bool 	isSigned() const;
	void	setStudent(Student* student);
	void	setCourse(Course *course);
	void	setProfessor(Professor* professor);
	void	setRoom(Classroom* room);
	virtual void execute() = 0;
	virtual void fill(const std::string& data) {
        _filledData = data;
    }
	virtual ~Form() {}
};

class CourseFinishedForm : public Form {
private:

public:
	CourseFinishedForm();
	void fill(const std::string& data);
	void execute();
};

class NeedMoreClassRoomForm : public Form {
private:

public:
	NeedMoreClassRoomForm();
	void fill(const std::string& data);
	void execute();
};

class NeedCourseCreationForm : public Form {
private:

public:
	NeedCourseCreationForm();
	void fill(const std::string& data);
	void execute();
};

class SubscriptionToCourseForm : public Form {
private:

public:
	SubscriptionToCourseForm();
	void fill(const std::string& data);
	void execute();
};


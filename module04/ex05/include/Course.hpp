#pragma once

#include <iostream>
#include <vector>
#include "Student.hpp"

class Professor;
class Student;

class Course {
	private:
		std::string _name;
		Professor* _responsable;
		std::vector<Student*> _students;
		size_t _numberOfClassToGraduate;
		size_t _maximumNumberOfStudent;
	public:
		Course(std::string p_name);
		Course(std::string p_name, size_t numberOfClassToGraduate, size_t maximumNumberOfStudent);
		const std::string&	get_name();
		size_t	getNumberOfClassToGraduate();
		size_t 	getMaxNumberOfStudents();
		Professor* getCourseResponsable();
		std::vector<Student*> getCourseStudents();
		void assign(Professor* p_professor);
		void subscribe(Student* p_student);
		void graduate(Student *p_student);
};


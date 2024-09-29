#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>
#include <vector>
#include "Staff.hpp"
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
		const std::string&	get_name();
		void assign(Professor* p_professor);
		void subscribe(Student* p_student);
};

#endif

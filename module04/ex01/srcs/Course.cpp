#include "Course.hpp"

Course::Course(std::string p_name): _name(p_name), 
    _responsable(nullptr), _numberOfClassToGraduate(0), _maximumNumberOfStudent(30) {
        std::cout << "Course " << this->_name << " is created\n";
    }

const std::string& Course::get_name() {return (this->_name);}

void Course::assign(Professor* p_professor) {
    this->_responsable = p_professor;
    std::cout << "Course " << this->_name << " is assigned to " << p_professor->get_name() << std::endl;
}

void Course::subscribe(Student* p_student) {
    if (this->_students.size() < this->_maximumNumberOfStudent) {
        this->_students.push_back(p_student);
        this->_numberOfClassToGraduate++;
    } else {
        std::cerr << "Course is full, subscription is not possible.\n"; 
    }
}

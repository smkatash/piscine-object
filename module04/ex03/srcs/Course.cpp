#include "Course.hpp"

Course::Course(std::string p_name): _name(p_name), 
    _responsable(nullptr), _numberOfClassToGraduate(5), _maximumNumberOfStudent(30) {
        std::cout << "Course " << this->_name << " is created\n";
    }

Course::Course(std::string p_name, size_t numberOfClassToGraduate, size_t maximumNumberOfStudent) : 
_name(p_name), _responsable(nullptr), _numberOfClassToGraduate(numberOfClassToGraduate), 
    _maximumNumberOfStudent(maximumNumberOfStudent) {
        std::cout << "Course " << this->_name << " is created.\n";
    }

const std::string& Course::get_name() {return this->_name;}

void Course::assign(Professor* p_professor) {
    this->_responsable = p_professor;
    //std::cout << "Course " << this->_name << " is assigned to " << p_professor->get_name() << std::endl;
}

size_t Course::getNumberOfClassToGraduate() {
    return this->_numberOfClassToGraduate;
}

Professor* Course::getCourseResponsable() {
    return this->_responsable;
}

void Course::subscribe(Student* p_student) {
    if (this->_students.size() < this->_maximumNumberOfStudent) {
        this->_students.push_back(p_student);
    } else {
        std::cerr << "Course is full, subscription is not possible.\n"; 
    }
}

void Course::graduate(Student *p_student) {
    std::vector<Student*>::iterator it = this->_students.begin();
    for (; it != this->_students.end(); ++it) {
        if (*it == p_student) {
            this->_students.erase(it);
            break;
        }
    }
}

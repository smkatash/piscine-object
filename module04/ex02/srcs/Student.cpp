#include "Student.hpp"

Student::Student(std::string p_name): Person(p_name){}

void Student::attendClass(Classroom* p_classroom) {
    if (p_classroom->canEnter(this)) {
        p_classroom->enter(this);
    }
}
void Student::exitClass() {
}

void Student::graduate(Course* p_course) {
}

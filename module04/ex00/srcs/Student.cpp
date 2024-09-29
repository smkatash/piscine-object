#include "Student.hpp"

void Student::attendClass(Classroom* p_classroom) {
    if (p_classroom->canEnter(this)) {
        p_classroom->enter(this);
    }
}
void Student::exitClass() {
}

void Student::graduate(Course* p_course) {
}
#include "Form.hpp"
#include "Headmaster.hpp"
#include "Secretary.hpp"
#include "Professor.hpp"
#include "Course.hpp"
#include "Observer.hpp"

int main() {
    Headmaster* headmaster = new Headmaster("Dr. Smith");
    Secretary* secretary = new Secretary("Ms. Johnson");
    Professor* prof = new Professor("Mr. Einstein");
    Course* physics = new Course("Physics");
    Student* student_a = new Student("Jake John");
    Student* student_b = new Student("Kate Middle");
    Student* student_c = new Student("Emilie Hahn");
    Student* student_d = new Student("Bob Anderson");
    Classroom* room = new Classroom();
    Observer* observer = new Observer(room);
    headmaster->setSecretary(secretary);
    prof->assignNewCourse(headmaster, physics);
    student_a->subscribe(physics);
    student_b->subscribe(physics);
    student_c->subscribe(physics);
    student_d->subscribe(physics);
    prof->assignNewClassroom(headmaster, room);
    std::cout << "<< *** OBSERVER ***  >>\n";
    observer->executeEvent(RingBell, headmaster);
    observer->executeEvent(RingBell, headmaster);
    observer->executeEvent(RingBell, headmaster);
    observer->executeEvent(RingBell, headmaster);
    observer->executeEvent(RingBell, headmaster);
    observer->executeEvent(RingBell, headmaster);
    observer->executeEvent(RingBell, headmaster);
    observer->executeEvent(RingBell, headmaster);
    observer->executeEvent(RingBell, headmaster);
    observer->executeEvent(RingBell, headmaster);
    observer->executeEvent(RingBell, headmaster);
    observer->executeEvent(RingBell, headmaster);
    prof->graduateStudent(headmaster, student_a, physics);
    prof->graduateStudent(headmaster, student_b, physics);
    prof->graduateStudent(headmaster, student_c, physics);
    prof->graduateStudent(headmaster, student_d, physics);
    delete headmaster;
    delete secretary;
    delete prof;
    delete physics;
    delete student_a;
    delete student_b;
    delete student_c;
    delete student_d;
}


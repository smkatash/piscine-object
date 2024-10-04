#include "Form.hpp"
#include "Headmaster.hpp"
#include "Secretary.hpp"
#include "Professor.hpp"
#include "Course.hpp"

void ProfessorPointOfView() {
    Headmaster* headmaster = new Headmaster("Dr. Smith");
    Secretary* secretary = new Secretary("Ms. Johnson");
    Professor* prof = new Professor("Mr. Einstein");
    Course* physics = new Course("Physics");
    Student* student = new Student("Jake John");
    Classroom* room = new Classroom();
    
    headmaster->setSecretary(secretary);
    prof->assignNewCourse(headmaster, physics);
    student->subscribe(physics);
    prof->assignNewClassroom(headmaster, room);
    for (size_t i = 0; i <= physics->getNumberOfClassToGraduate(); ++i) {
        headmaster->attendClass(student, prof, room);
    }
    prof->graduateStudent(headmaster, student, physics);
    delete headmaster;
    delete secretary;
    delete prof;
    delete physics;
    delete student;
}

void ProfessorPointOfViewRoom() {
    Headmaster* headmaster = new Headmaster("Dr. Smith");
    Secretary* secretary = new Secretary("Ms. Johnson");
    Professor* prof_a = new Professor("Mr. Einstein");
    Professor* prof_b = new Professor("Mr. Oppenheimer");
    Course* physics_a = new Course("Physics I");
    Course* physics_b = new Course("Physics II");
    Student* student = new Student("Jake John");
    Classroom* room = new Classroom();
    
    headmaster->setSecretary(secretary);
    prof_a->assignNewCourse(headmaster, physics_a);
    prof_b->assignNewCourse(headmaster, physics_b);
    student->subscribe(physics_a);
    student->subscribe(physics_b);
    prof_a->assignNewClassroom(headmaster, room);
    prof_b->assignNewClassroom(headmaster, room);
    for (size_t i = 0; i <= physics_a->getNumberOfClassToGraduate(); ++i) {
        headmaster->attendClass(student, prof_a, room);
    }
    for (size_t i = 0; i <= physics_b->getNumberOfClassToGraduate(); ++i) {
        headmaster->attendClass(student, prof_b, room);
    }
    prof_a->graduateStudent(headmaster, student, physics_a);
    prof_b->graduateStudent(headmaster, student, physics_b);
    delete headmaster;
    delete secretary;
    delete prof_a;
    delete prof_b;
    delete physics_a;
    delete physics_b;
    delete student;
}

void ProfessorPointOfViewInvalid() {
    Headmaster* headmaster = new Headmaster("Dr. Smith");
    Secretary* secretary = new Secretary("Ms. Johnson");
    Professor* prof = new Professor("Mr. Einstein");
    Course* physics = new Course("Physics");
    Student* student = new Student("Jake John");
    // assign without secretary
    prof->assignNewCourse(headmaster, physics);
    // assign with secretary
    headmaster->setSecretary(secretary);
    prof->assignNewCourse(headmaster, physics);

    // teach without student
    for (size_t i = 0; i <= physics->getNumberOfClassToGraduate(); ++i) {
        prof->doClass(student);
    }
    // teach with student
    student->subscribe(physics);
    for (size_t i = 0; i <= physics->getNumberOfClassToGraduate(); ++i) {
        prof->doClass(student);
    }
    // graduate student without attendance
    Student* studentin = new Student("Emilie Kate");
    studentin->subscribe(physics);
    prof->graduateStudent(headmaster, studentin, physics);
    // graduate student with attendance
    prof->graduateStudent(headmaster, student, physics);

    delete headmaster;
    delete secretary;
    delete prof;
    delete physics;
    delete student;
    delete studentin;
}

void StudentPointOfView() {
    Headmaster* headmaster = new Headmaster("Dr. Smith");
    Secretary* secretary = new Secretary("Ms. Johnson");
    Professor* prof = new Professor("Mr. Einstein");
    Course* physics = new Course("Physics");
    Student* student = new Student("Jake John");
    Classroom* room = new Classroom();
    
    headmaster->setSecretary(secretary);
    student->subscribeToNewCourse(headmaster, physics);
    prof->assignNewCourse(headmaster, physics);
    prof->assignNewClassroom(headmaster, room);
    for (size_t i = 0; i <= physics->getNumberOfClassToGraduate(); ++i) {
        headmaster->attendClass(student, prof, room);
    }
    prof->graduateStudent(headmaster, student, physics);
    delete headmaster;
    delete secretary;
    delete prof;
    delete physics;
    delete student;
}
 
void StudentPointOfViewInvalid() {
    Headmaster* headmaster = new Headmaster("Dr. Smith");
    Secretary* secretary = new Secretary("Ms. Johnson");
    Professor* prof = new Professor("Mr. Einstein");
    Course* physics = new Course("Physics");
    Student* student = new Student("Jake John");
    
    // assign without secretary
    student->subscribeToNewCourse(headmaster, physics);
    prof->assignNewCourse(headmaster, physics);
    // teach without subscription and form
    for (size_t i = 0; i <= physics->getNumberOfClassToGraduate(); ++i) {
        headmaster->attendClass(student, prof, nullptr);
    }
    // graduate without form
    prof->graduateStudent(headmaster, student, physics);
    delete headmaster;
    delete secretary;
    delete prof;
    delete physics;
    delete student;
}
 

int main() {
    ProfessorPointOfView();
    ProfessorPointOfViewRoom();
    ProfessorPointOfViewInvalid();
    StudentPointOfView();
    StudentPointOfViewInvalid();
}


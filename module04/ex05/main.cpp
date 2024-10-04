#include "School.hpp"

void    createResources(School *school) {
    std::string courseNames[7] = {"Physics", "Calculus", "Geography", "History", "Statistics", "Economy", "Informatics"};
    std::string studentNames[28] = { "Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Helen", "Jack", "Ivy", 
        "Liam", "Mia", "Noah", "Olivia", "Paul", "Quincy", "Rita", "Sam", "Tina", "Uma", 
        "Victor", "Wendy", "Xander", "Yara", "Zane", "Makiah", "Bruce", "Leo"};
    std::string professorNames[7] = { "Dr. Alice Smith", "Prof. Bob Johnson", "Dr. Charlie Brown", "Prof. David White", "Dr. Eva Black", 
    "Prof. Frank Green", "Dr. Grace Adams"};
    for (int i = 0; i < 7; ++i) {
        school->recruteProfessor(new Professor(professorNames[i]));
    }
    for (int i = 0; i < 28; ++i){
        school->recruteStudent(new Student(studentNames[i]));
    }
    for (int i = 0; i < 7; ++i) {
        school->addCourse(new Course(courseNames[i], 15, 4));
        Classroom* room = new Classroom();
        school->addClassroom(room);
        school->addObserver(new Observer(room));
    }
}

void    cleanUp(School* school) {
    std::vector<Professor*> profs = school->getProfessors();
    std::vector<Professor*>::iterator itp = profs.begin();
    for (; itp != profs.end(); ++itp) {
        delete *itp;
    }

    std::vector<Student*> students = school->getStudents();
    std::vector<Student*>::iterator its = students.begin();
    for (; its != students.end(); ++its) {
        delete *its;
    }

    std::vector<Course*> courses = school->getAllCourses();
    std::vector<Course*>::iterator itc = courses.begin();
    for (; itc != courses.end(); ++itc) {
        delete *itc;
    }

    std::vector<Classroom*> rooms = school->getClassrooms();
    std::vector<Classroom*>::iterator itcl = rooms.begin();
    for (; itcl != rooms.end(); ++itcl) {
        delete *itcl;
    }
    
    std::vector<Observer*> observers = school->getObservers();
    std::vector<Observer*>::iterator ito = observers.begin();
    for (; ito != observers.end(); ++ito) {
        delete *ito;
    }

}

int main() {
    School *school = new School();
    createResources(school);
    
    school->runDayRoutine();
    school->runDayRoutine();
    school->runDayRoutine();
    school->runDayRoutine();
    school->runDayRoutine();
    
    school->graduationCeremony();
    school->requestRingBell();
    cleanUp(school);
}



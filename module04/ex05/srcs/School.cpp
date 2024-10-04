#include "School.hpp"

School::School() {
    this->_headmaster = new Headmaster("Headmaster");
    this->_secretary = new Secretary("Secretary");
    this->_headmaster->setSecretary(this->_secretary);
}
	
School::~School(){
    delete this->_headmaster;
    delete this->_secretary;
}

Course*	School::getCourse(std::string name) {
    std::vector<Course*>::iterator it = this->_courses.begin();
    for (; it != this->_courses.end(); ++it) {
        if (name.compare((*it)->get_name()) == 0) {
            return *it;
        }
    }
    return nullptr;
}

std::vector<Course*>		School::getAllCourses() { return this->_courses; }
std::vector<Student*>       School::getStudents() { return this->_students; }
std::vector<Professor*>	    School::getProfessors() { return this->_professors; }
std::vector<Observer*>	    School::getObservers() { return this->_observers; }
std::vector<Classroom*>	    School::getClassrooms() { return this->_rooms; }
Headmaster*			        School::getHeadmaster() { return this->_headmaster; }
Secretary*			        School::getSecretary() { return this->_secretary; }

void	School::requestRingBell(void){
	std::vector<Observer*>::iterator it = this->_observers.begin();
    for (; it != this->_observers.end(); ++it) {
        this->_headmaster->executeEvent(RingBell, *it);
    }
}

void    School::addCourse(Course* course) {
    std::vector<Course*>::iterator it = this->_courses.begin();
    for (; it != this->_courses.end(); ++it) {
        if (course == *it || course->get_name().compare((*it)->get_name()) == 0) {
           return ;
        }
        
    }
    this->_courses.push_back(course);
}
void    School::addClassroom(Classroom* room) {
    std::vector<Classroom*>::iterator it = this->_rooms.begin();
    for (; it != this->_rooms.end(); ++it) {
        if (room == *it) {
           return ;
        }
        
    }
    this->_rooms.push_back(room);
}

void    School::addObserver(Observer* observer) {
    std::vector<Observer*>::iterator it = this->_observers.begin();
    for (; it != this->_observers.end(); ++it) {
        if (observer == *it) {
           return ;
        }
    }
    this->_observers.push_back(observer);
}

void    School::recruteProfessor(Professor* professor) {
    std::vector<Professor*>::iterator it = this->_professors.begin();
        for (; it != this->_professors.end(); ++it) {
            if (professor == *it || professor->get_name().compare((*it)->get_name()) == 0) {
                return ;
            }
        }
    this->_professors.push_back(professor);

}

void	School::recruteStudent(Student* student) {
    std::vector<Student*>::iterator it = this->_students.begin();
    for (; it != this->_students.end(); ++it) {
        if (student == *it || student->get_name().compare((*it)->get_name()) == 0) {
            return ;
        }  
    }
    this->_students.push_back(student);
}

void	School::graduationCeremony() {
    std::cout << "\n\n***************** Graduation ****************\n\nn";
    for (size_t i = 0; i < this->_courses.size(); ++i) {
       Professor *prof = this->_professors[i];
       Course *course = this->_courses[i];
       this->_headmaster->graduateStudents(prof, course);
    }
}

void	School::launchClasses() {
    if (this->_professors.size() != this->_courses.size()) {
		std::cerr << "Not enough professors or courses\n";
        return ;
    }
    if (this->_rooms.size() < this->_courses.size()) {
		std::cerr << "Not enough rooms.\n";
        return ;
    }
    size_t last_idx = 0;
    for (size_t i = 0; i < this->_courses.size(); ++i) {
       Professor *prof = this->_professors[i];
       Course *course = this->_courses[i];
       Classroom *room = this->_rooms[i];
       this->_headmaster->assignProfessorToCourse(prof, course);
       this->_headmaster->assignRoomToProfessor(prof, room);
       for (size_t idx = 0; idx < course->getMaxNumberOfStudents(); ++idx) {
            if (this->_students[idx + last_idx]) {
                std::cout << this->_students[idx + last_idx]->get_name() << " is assigned\n";
                this->_headmaster->assignStudentToCourse(this->_students[idx + last_idx], course);
            }
       }
       last_idx += course->getMaxNumberOfStudents();
    }
}

void School::runDayRoutine() {
    this->launchClasses();

    for (int i = 0; i <= 7; ++i) {
        this->requestRingBell();
    }
}

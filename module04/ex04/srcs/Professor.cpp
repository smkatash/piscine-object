#include "Professor.hpp"

Professor::Professor(std::string p_name) : Staff(p_name), _currentCourse(nullptr){}


void Professor::setCourse(Course* p_course) {
    this->_currentCourse = p_course;
}
void Professor::setClassroom(Room* room) {
    this->_currentRoom = room;
}

Course*	Professor::getCurrentCourse() {
    return this->_currentCourse;
}

void Professor::doClass(Student* student) {
    if (!this->_currentRoom) {
        std::cerr << "Professor needs a Room to teach.\n ";
        return ;
    }
    if (!this->_currentCourse) {
        std::cerr << "Professor needs a Course to teach.\n ";
        return ;
    }
    if (this->_currentCourse && student->isSubscribed(this->_currentCourse)) {
        this->enterClass(this->_currentRoom);
        std::cout << "Professor is teaching  " << this->_currentCourse->get_name() << ".\n";
        student->attendClass(this->_currentCourse, this->_currentRoom);
        student->takeNotes();
        this->_currentRoom->printOccupant();
        student->exitClass(this->_currentRoom);
        this->exitClass(this->_currentRoom);
        std::cout << "Professor finished teaching " << this->_currentCourse->get_name() << ".\n";
        this->_currentRoom->printOccupant();
    } else {
        std::cerr << "Student is not subscribed to the Course\n";
    }
}
void Professor::closeCourse() {
    this->_currentCourse->assign(nullptr);
    this->_currentCourse = nullptr;
}

void Professor::exitClass(Room *room) {
    this->_currentRoom = nullptr;
    room->exit(this);
}
void Professor::enterClass(Room *room) {
    this->_currentRoom = room;
    room->enter(this);
}

void    Professor::fillForm(Form* form, Student* student, Course* course, Classroom *room) {
    form->setCourse(course);
    form->setStudent(student);
    form->setRoom(room);
    form->setProfessor(this);
    form->fill("Form filled by Professor." );
}

void	Professor::graduateStudent(Headmaster* headmaster, Student* student, Course* course){
	CourseFinishedForm *form = headmaster->requestCourseFinishedForm();
	if (!form)
		return ;
	this->fillForm(form, student, course, nullptr);
    std::cout << "Request to sign the Form.\n";
    headmaster->signForm(form);
}

void	Professor::assignNewCourse(Headmaster* headmaster, Course* course) {
    NeedCourseCreationForm *form = headmaster->requestCourseCreationForm();
    if (!form) {
        return ;
    }
    this->fillForm(form, nullptr, course, nullptr);
    std::cout << "Request to sign the Form.\n";
    headmaster->signForm(form);
    if (form->isSigned()) {
        course->assign(this);
        this->setCourse(course);
    }
}

void	Professor::assignNewClassroom(Headmaster* headmaster, Classroom *room) {
    if (this->_currentCourse && headmaster && room) {
        NeedMoreClassRoomForm *form = headmaster->requestClassroomForm();
        if (!form) {
            return ;
        }
        this->fillForm(form, nullptr, this->_currentCourse, room);
        std::cout << "Request to sign the Form.\n";
        headmaster->signForm(form);
    } else {
        std::cerr << "Professor needs a Course first. Classroom cannot be assigned\n";
    }
}

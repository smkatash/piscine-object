#include "Student.hpp"

Student::Student(std::string p_name): Person(p_name){}

void    Student::takeNotes() {
    std::cout << "Student is taking notes.\n";
}

void Student::attendClass(Course *p_course, Room *room) {
    this->enterClass(room);
    std::map<Course*, size_t>::iterator it = this->_subscribedCourse.begin();
    for (; it != this->_subscribedCourse.end(); ++it) {
            if (it->first == p_course) {
                it->second++;
                std::cout << "Student is attending the class.\n";
                break;
        }
    }
}

void    Student::enterClass(Room *room) {
    room->enter(this);
    this->_currentRoom = room;
}

size_t Student::numberOfAttendedClasses(Course* p_course) {
    std::map<Course*, size_t>::iterator it = this->_subscribedCourse.begin();
    for (; it != this->_subscribedCourse.end(); ++it) {
        if (it->first == p_course) {
            return (it->second);
        }
    }
    return (0);
}

void Student::subscribe(Course* p_course) {
    if (this->_subscribedCourse.find(p_course) != this->_subscribedCourse.end()) {
        return;
    }
    p_course->subscribe(this);
    this->_subscribedCourse.insert(std::make_pair(p_course, 0));
}

bool Student::isSubscribed(Course* p_course) {
    if (this->_subscribedCourse.find(p_course) != this->_subscribedCourse.end()) {
        return (true);
    }
    return (false);
}

void    Student::fillForm(Form* form, Course* course) {
    form->setCourse(course);
    form->setStudent(this);
    form->fill("Form filled by Student." );
}

void Student::subscribeToNewCourse(Headmaster* headmaster, Course* p_course) {
    SubscriptionToCourseForm* form = headmaster->requestCourseSubscriptionForm();
    if (!form) {
        return ;
    }
    this->fillForm(form, p_course);
    std::cout << "Request to sign the Form.\n";
    headmaster->signForm(form);
}

void Student::exitClass(Room* room) {
    this->_currentRoom = nullptr;
    room->exit(this);
}

void Student::graduate(Course* p_course) {
    std::map<Course*, size_t>::iterator it = this->_subscribedCourse.begin();
    for (; it != this->_subscribedCourse.end(); ++it) {
        if (it->first == p_course) {
            this->_subscribedCourse.erase(it);
            break;
        }
    }
}

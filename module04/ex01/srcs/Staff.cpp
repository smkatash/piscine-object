#include "Staff.hpp"

Staff::Staff(std::string p_name) : Person(p_name){}
Headmaster::Headmaster(std::string p_name) : Staff(p_name){}
Secretary::Secretary(std::string p_name) : Staff(p_name){}
Professor::Professor(std::string p_name) : Staff(p_name){}

void    Staff::sign(Form* p) {
}

void Headmaster::receiveForm(Form* p_form) {
    this->_formToValidate.push_back(p_form);
}

Form* Secretary::createForm(FormTypes::Type p_formType) {
    switch(p_formType) {
        case FormTypes::CourseFinished:
            return new CourseFinishedForm();
        case FormTypes::NeedMoreClassRoom:
            return new NeedMoreClassRoomForm();
        case FormTypes::NeedCourseCreation:
            return new NeedCourseCreationForm();
        case FormTypes::SubscriptionToCourse:
            return new SubscriptionToCourseForm();
    }
    return nullptr;
}

void Secretary::archiveForm() {
}

void Professor::assignCourse(Course* p_course) {
    this->_currentCourse = p_course;
    this->_currentCourse->assign(this);
}

void Professor::doClass() {}
void Professor::closeCourse() {
    this->_currentCourse->assign(nullptr);
    this->_currentCourse = nullptr;
}

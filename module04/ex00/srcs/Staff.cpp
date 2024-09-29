#include "Staff.hpp"

void    Staff::sign(Form* p) {
}

void Headmaster::receiveForm(Form* p_form) {
    this->_formToValidate.push_back(p_form);
}

Form* Secretary::createForm(FormType p_formType) {
    switch(p_formType) {
        case FormType::CourseFinished:
            return new CourseFinishedForm();
        case FormType::NeedMoreClassRoom:
            return new NeedMoreClassRoomForm();
        case FormType::NeedCourseCreation:
            return new NeedCourseCreationForm();
        case FormType::SubscriptionToCourse:
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


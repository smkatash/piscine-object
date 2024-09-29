#include "Form.hpp"

Form::Form(FormTypes::Type p_formType): _formType(p_formType), _is_signed(false) {}

void    Form::sign() {
    this->_is_signed = true;
}

bool    Form::is_signed() const {
    return (this->_is_signed);
}

CourseFinishedForm::CourseFinishedForm() : Form(FormTypes::CourseFinished) {}

void CourseFinishedForm::execute() {
    if (this->is_signed()) {
        std::cout << "CourseFinishedForm executed.\n";
    } else {
        std::cout << "Form not signed. Cannot execute.\n";
    }
}

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormTypes::NeedMoreClassRoom) {}

void NeedMoreClassRoomForm::execute() {
    if (this->is_signed()) {
        std::cout << "NeedMoreClassRoomForm executed.\n" << std::endl;
    } else {
        std::cout << "Form not signed. Cannot execute.\n";
    }
}

NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormTypes::NeedCourseCreation) {}

void NeedCourseCreationForm::execute() {
    if (this->is_signed()) {
        std::cout << "NeedCourseCreationForm executed\n";
    } else {
        std::cout << "Form not signed. Cannot execute.\n";
    }
}

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormTypes::SubscriptionToCourse) {}


void SubscriptionToCourseForm::execute() {
    if (this->is_signed()) {
        std::cout << "SubscriptionToCourseForm executed.\n";
    } else {
        std::cout << "Form not signed. Cannot execute.\n";
    }
}

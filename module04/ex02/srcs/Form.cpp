#include "Form.hpp"

Form::Form(FormTypes::Type p_formType): _formType(p_formType), _isSigned(false) {}

void    Form::sign() {
    if (!this->_filledData.empty()) {
        this->_isSigned = true;
    }
}

bool    Form::isSigned() const {
    return (this->_isSigned);
}

CourseFinishedForm::CourseFinishedForm() : Form(FormTypes::CourseFinished) {}

void CourseFinishedForm::execute() {
    if (this->isSigned()) {
        std::cout << "CourseFinishedForm executed.\n";
    } else {
        std::cout << "Form not signed. Cannot execute.\n";
    }
}

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormTypes::NeedMoreClassRoom) {}

void NeedMoreClassRoomForm::execute() {
    if (this->isSigned()) {
        std::cout << "NeedMoreClassRoomForm executed.\n" << std::endl;
    } else {
        std::cout << "Form not signed. Cannot execute.\n";
    }
}

NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormTypes::NeedCourseCreation) {}

void NeedCourseCreationForm::execute() {
    if (this->isSigned()) {
        std::cout << "NeedCourseCreationForm executed\n";
    } else {
        std::cout << "Form not signed. Cannot execute.\n";
    }
}

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormTypes::SubscriptionToCourse) {}


void SubscriptionToCourseForm::execute() {
    if (this->isSigned()) {
        std::cout << "SubscriptionToCourseForm executed.\n";
    } else {
        std::cout << "Form not signed. Cannot execute.\n";
    }
}

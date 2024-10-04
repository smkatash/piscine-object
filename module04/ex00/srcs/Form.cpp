#include "Form.hpp"

Form::Form(FormType p_formType): _formType(p_formType) {};

void CourseFinishedForm::execute() {
    std::cout << "CourseFinishedForm executed.\n";
}

void NeedMoreClassRoomForm::execute() {
    std::cout << "NeedMoreClassRoomForm executed.\n";
}

void NeedCourseCreationForm::execute() {
    std::cout << "NeedCourseCreationForm executed.\n";
}

void SubscriptionToCourseForm::execute() {
    std::cout << "SubscriptionToCourseForm executed.\n";
}

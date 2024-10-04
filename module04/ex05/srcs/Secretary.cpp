#include "Secretary.hpp"
#include "Form.hpp"

Secretary::Secretary(std::string p_name) : Staff(p_name){}


void    Staff::sign(Form* p) {
    p->sign();
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

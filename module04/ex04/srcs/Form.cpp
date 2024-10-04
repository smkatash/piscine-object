#include "Form.hpp"

Form::Form(FormTypes::Type p_formType): 
    _formType(p_formType), _isSigned(false), _filledData(""),
    _student(nullptr), _course(nullptr), _professor(nullptr),
    _room(nullptr) {}

void    Form::sign() {
    if (!this->_filledData.empty()) {
        this->_isSigned = true;
    } else {
        std::cout << "Form is empty, cannot be signed." << std::endl;
    }
}

bool    Form::isSigned() const {
    return (this->_isSigned);
}

void	Form::setStudent(Student* student) {
    this->_student = student;
}
void	Form::setCourse(Course* course) {
    this->_course = course;
}
void	Form::setProfessor(Professor* professor) {
    this->_professor = professor;
}
void	Form::setRoom(Classroom* room) {
    this->_room = room;
}

CourseFinishedForm::CourseFinishedForm() : Form(FormTypes::CourseFinished) {}
void CourseFinishedForm::fill(const std::string& data)  {
    if (this->_student && this->_course && 
        (this->_course->getNumberOfClassToGraduate() <= this->_student->numberOfAttendedClasses(this->_course))) {
        std::cout << "Course is finished.\n";
        this->_filledData = data;
        this->_isSigned = true;
    } else {
        std::cerr << "Course is not finished. Form incomplete. Attend more classes!\n";
        this->_isSigned = false;
    }
}

void CourseFinishedForm::execute() {
    if (this->isSigned()) {
        std::cout << "CourseFinishedForm is executed.\n";
        this->_course->graduate(this->_student);
        this->_student->graduate(this->_course);
        std::cout << "Student is released from the Course.\n";
    } else {
        std::cout << "Form not signed. Cannot execute.\n";
    }
}

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormTypes::NeedMoreClassRoom) {}
void NeedMoreClassRoomForm::fill(const std::string& data)  {
    if (this->_course && this->_professor && this->_room && this->_room->canEnter()) {
        std::cout << "Classroom is needed.\n";
        this->_filledData = data;
        this->_isSigned = true;
    } else {
        std::cerr << "Form for Classroom incomplete!\n";
        this->_isSigned = false;
    }
}
void NeedMoreClassRoomForm::execute() {
    if (this->isSigned()) {
        std::cout << "NeedMoreClassRoomForm is executed.\n" << std::endl;
        this->_professor->setClassroom(this->_room);
        this->_room->assignCourse(this->_course);
    } else {
        std::cout << "Form not signed. Cannot execute.\n";
    }
}

NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormTypes::NeedCourseCreation) {}
void NeedCourseCreationForm::fill(const std::string& data)  {
    if (this->_course && this->_professor) {
        std::cout << "Course is needed.\n";
        this->_filledData = data;
        this->_isSigned = true;
    } else {
        std::cerr << "Form for Course incomplete!\n";
        this->_isSigned = false;
    }
}
void NeedCourseCreationForm::execute() {
    if (this->isSigned()) {
        std::cout << "NeedCourseCreationForm is executed\n";
    } else {
        std::cout << "Form not signed. Cannot execute.\n";
    }
}

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormTypes::SubscriptionToCourse) {}
void SubscriptionToCourseForm::fill(const std::string& data)  {
    if (this->_course && this->_student) {
        std::cout << "Subscription to a course.\n";
        this->_filledData = data;
        this->_isSigned = true;
    } else {
        std::cerr << "Form for Course Subscription incomplete!\n";
        this->_isSigned = false;
    }
}

void SubscriptionToCourseForm::execute() {
    if (this->isSigned()) {
         this->_course->subscribe(this->_student);
        this->_student->subscribe(this->_course);
        std::cout << "SubscriptionToCourseForm is executed.\n";
    } else {
        std::cout << "Form not signed. Cannot execute.\n";
    }
}

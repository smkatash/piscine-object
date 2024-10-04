#include "Headmaster.hpp"

Headmaster::Headmaster(std::string p_name) : Staff(p_name), _secretary(nullptr) {}

void    Headmaster::attendClass(Student *p_student, Professor *professor, Classroom *p_classroom) {
    if (!p_student || !professor || !p_classroom) {
        std::cerr << "Conditions for Class are not met.\n";
        return ;
    }
    if (!p_classroom->canEnterClassroom()) {
        std::cerr << "Classroom is occupied. Request a new Classroom\n";
        return ;
    }
    Course* p_course = professor->getCurrentCourse();
    if (p_course && p_student->isSubscribed(p_course) && (p_course->getCourseResponsable() == professor)) {
        p_classroom->assignCourse(p_course);
        professor->doClass(p_student);
        p_classroom->removeCourse();
    } else {
        std::cerr << "Student can not attend class.\n";
    }

}
void	Headmaster::assignProfessorToCourse(Professor* professor, Course* course){
	if (!professor)
		return ;
	professor->assignNewCourse(this, course);
}

void	Headmaster::assignStudentToCourse(Student* student, Course* course){
	if (!student || !course)
		return ;
	student->subscribe(course);
}

void	Headmaster::assignRoomToProfessor(Professor* professor, Classroom *room){
	if (!professor || !room)
		return ;
	professor->assignNewClassroom(this, room);
}

void Headmaster::graduateStudents(Professor* professor, Course *course) {
    std::vector<Student*> students = course->getCourseStudents();
    std::vector<Student*>::iterator stud_it = students.begin();
    for (; stud_it != students.end(); ++stud_it) {
        professor->graduateStudent(this, *stud_it, course);
    }
}

void    Headmaster::executeEvent(Event event, Observer *observer) {
    observer->executeEvent(event, this);
}

void Headmaster::receiveForm(Form* p_form) {
    this->_formToValidate.push_back(p_form);
}

void    Headmaster::setSecretary(Secretary *secretary) {
    this->_secretary = secretary;
    std::cout << "Secretary is assigned\n";
}

CourseFinishedForm* Headmaster::requestCourseFinishedForm() {
    if (this->_secretary) {
        return static_cast<CourseFinishedForm*>(this->_secretary->createForm(FormTypes::CourseFinished));
    }
    std::cerr << "No secretary available to generate a form.\n";
    return nullptr;
}

NeedCourseCreationForm* Headmaster::requestCourseCreationForm() {
    if (this->_secretary) {
        return static_cast<NeedCourseCreationForm*>(this->_secretary->createForm(FormTypes::NeedCourseCreation));
    }
    std::cerr << "No secretary available to generate a form.\n";
    return nullptr;
}

SubscriptionToCourseForm* Headmaster::requestCourseSubscriptionForm(){
    if (this->_secretary) {
        return static_cast<SubscriptionToCourseForm*>(this->_secretary->createForm(FormTypes::SubscriptionToCourse));
    }
    std::cerr << "No secretary available to generate a form.\n";
    return nullptr;
}

NeedMoreClassRoomForm* Headmaster::requestClassroomForm(){
    if (this->_secretary) {
        return static_cast<NeedMoreClassRoomForm*>(this->_secretary->createForm(FormTypes::NeedMoreClassRoom));
    }
    std::cerr << "No secretary available to generate a form.\n";
    return nullptr;
}


void Headmaster::signForm(Form* p_form) {
    this->sign(p_form);
    if (p_form->isSigned()) {
        std::cout << "Headmaster has signed the Form.\n";
        p_form->execute();
    } else {
        std::cerr << "Headmaster cannot sign the Form. Requirements not fullfiled.\n";
    }
}

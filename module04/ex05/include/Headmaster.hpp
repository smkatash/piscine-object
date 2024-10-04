#pragma once

#include "Staff.hpp"
#include "Form.hpp"
#include "Secretary.hpp"
#include "Professor.hpp"
#include "Observer.hpp"
#include "Room.hpp"
#include <vector>

class CourseFinishedForm;
class NeedCourseCreationForm;
class SubscriptionToCourseForm;
class NeedMoreClassRoomForm;
class Observer;

class Headmaster : public Staff {
private:
    Secretary* _secretary;
	std::vector<Form*> _formToValidate;
	
public:
	Headmaster(std::string p_name);
    void    setSecretary(Secretary *secretary);
	void    receiveForm(Form* p_form);
	void	signForm(Form* p_form);
    void    attendClass(Student *p_student, Professor *professor, Classroom *p_classroom);
    void    executeEvent(Event event, Observer *observer);
    void	assignProfessorToCourse(Professor* professor, Course* course);
    void	assignStudentToCourse(Student* student, Course* course);
    void	assignRoomToProfessor(Professor* professor, Classroom *room);
    void	graduateStudents(Professor* professor, Course *course);
    CourseFinishedForm* requestCourseFinishedForm();
    NeedCourseCreationForm* requestCourseCreationForm();
    SubscriptionToCourseForm* requestCourseSubscriptionForm();
    NeedMoreClassRoomForm*  requestClassroomForm();
};


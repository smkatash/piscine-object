#pragma once

#include "Staff.hpp"
#include "Form.hpp"
#include "Secretary.hpp"
#include "Professor.hpp"
#include "Room.hpp"
#include <vector>

class CourseFinishedForm;
class NeedCourseCreationForm;
class SubscriptionToCourseForm;
class NeedMoreClassRoomForm;

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
    CourseFinishedForm* requestCourseFinishedForm();
    NeedCourseCreationForm* requestCourseCreationForm();
    SubscriptionToCourseForm* requestCourseSubscriptionForm();
    NeedMoreClassRoomForm*  requestClassroomForm();
};


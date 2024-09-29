#ifndef FORM_HPP
#define FORM_HPP
#include "FormType.hpp"
#include <iostream>

class Form {
private:
	FormType _formType;

public:
	Form(FormType p_formType);

	virtual void execute() = 0;
};

class CourseFinishedForm : public Form {
private:

public:
	CourseFinishedForm() : Form(FormType::CourseFinished) {}
	void execute();
};

class NeedMoreClassRoomForm : public Form {
private:

public:
	NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom) {}
	void execute();
};

class NeedCourseCreationForm : public Form {
private:

public:
	NeedCourseCreationForm() : Form(FormType::NeedCourseCreation) {}
	void execute();
};

class SubscriptionToCourseForm : public Form {
private:

public:
	SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse) {}
	void execute();
};

#endif

#ifndef FORM_HPP
#define FORM_HPP
#include "FormType.hpp"
#include <iostream>

class Form {
private:
	FormTypes::Type _formType;

public:
	Form(FormTypes::Type p_formType);

	virtual void execute() = 0;
};

class CourseFinishedForm : public Form {
private:

public:
	CourseFinishedForm() : Form(FormTypes::CourseFinished) {}
	void execute();
};

class NeedMoreClassRoomForm : public Form {
private:

public:
	NeedMoreClassRoomForm() : Form(FormTypes::NeedMoreClassRoom) {}
	void execute();
};

class NeedCourseCreationForm : public Form {
private:

public:
	NeedCourseCreationForm() : Form(FormTypes::NeedCourseCreation) {}
	void execute();
};

class SubscriptionToCourseForm : public Form {
private:

public:
	SubscriptionToCourseForm() : Form(FormTypes::SubscriptionToCourse) {}
	void execute();
};

#endif

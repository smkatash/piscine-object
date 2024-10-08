#ifndef FORM_HPP
#define FORM_HPP
#include "FormType.hpp"
#include <iostream>

class Form {
private:
	FormTypes::Type _formType;
	bool			_isSigned;

public:
	Form(FormTypes::Type p_formType);
	void	sign();
	bool 	isSigned() const;
	virtual void execute() = 0;
	virtual ~Form() {}
};

class CourseFinishedForm : public Form {
private:

public:
	CourseFinishedForm();
	void execute();
};

class NeedMoreClassRoomForm : public Form {
private:

public:
	NeedMoreClassRoomForm();
	void execute();
};

class NeedCourseCreationForm : public Form {
private:

public:
	NeedCourseCreationForm();
	void execute();
};

class SubscriptionToCourseForm : public Form {
private:

public:
	SubscriptionToCourseForm();
	void execute();
};

#endif

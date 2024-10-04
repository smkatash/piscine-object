#pragma once

#include "Staff.hpp"
#include "FormType.hpp"
#include <vector>

class Secretary : public Staff {
private:

public:
	Secretary(std::string p_name);
	Form* createForm(FormTypes::Type p_formType);
	void archiveForm();
};


#include "Staff.hpp"
#include "Form.hpp"

int main() {
    Headmaster* headmaster = new Headmaster("Dr. Smith");
    Secretary* secretary = new Secretary("Ms. Johnson");

    Form* courseFinishedForm = secretary->createForm(FormTypes::CourseFinished);
    headmaster->receiveForm(courseFinishedForm);

    courseFinishedForm->execute();
    headmaster->signForm(courseFinishedForm);

    courseFinishedForm->execute();

    delete headmaster;
    delete secretary;
    delete courseFinishedForm;
}


#include "StudentList.hpp"
#include "StaffList.hpp"
#include "CourseList.hpp"
#include "RoomList.hpp"

int main() {
    StudentList::get_instance()->add(new Student("A"));
	StudentList::get_instance()->add(new Student("B"));
	StudentList::get_instance()->add(new Student("C"));
	StudentList::get_instance()->add(new Student("D"));

	StaffList::get_instance()->add(new Headmaster("Mr. A"));
	StaffList::get_instance()->add(new Secretary("Mrs. B"));
	StaffList::get_instance()->add(new Professor("Mr. C"));
	StaffList::get_instance()->add(new Staff("Mrs. D"));

	CourseList::get_instance()->add(new Course("Calculus"));
	CourseList::get_instance()->add(new Course("Literature"));
	CourseList::get_instance()->add(new Course("Biology"));
	CourseList::get_instance()->add(new Course("Physics"));

	RoomList::get_instance()->add(new Classroom());
	RoomList::get_instance()->add(new Classroom());
	RoomList::get_instance()->add(new Classroom());
	RoomList::get_instance()->add(new Classroom());

	std::vector<Student*> students = StudentList::get_instance()->get_list();
	std::vector<Staff*> staff = StaffList::get_instance()->get_list();
	std::vector<Course*> courses = CourseList::get_instance()->get_list();
	std::vector<Room*> rooms = RoomList::get_instance()->get_list();

    std::cout << "List of students:" << std::endl;
    for (std::vector<Student*>::iterator it = students.begin(); it != students.end(); ++it) {
        std::cout << (*it)->get_name()  << std::endl;
    }

    std::cout << "List of staff:" << std::endl;
    for (std::vector<Staff*>::iterator it = staff.begin(); it != staff.end(); ++it) {
        std::cout << (*it)->get_name()  << std::endl;
    }

    std::cout << "List of courses:" << std::endl;
    for (std::vector<Course*>::iterator it = courses.begin(); it != courses.end(); ++it) {
        std::cout << (*it)->get_name()  << std::endl;
    }

    std::cout << "List of rooms:" << std::endl;
    for (std::vector<Room*>::iterator it = rooms.begin(); it != rooms.end(); ++it) {
        std::cout << (*it)->get_id()  << std::endl;
    }

    std::cout << "Indexes :" << std::endl;
	for (int i = 3; i >=0; --i)
	{
		Student *student = StudentList::get_instance()->operator[](i);
		Staff *staff = StaffList::get_instance()->operator[](i);
		Course *course = CourseList::get_instance()->operator[](i);
		Room *room = RoomList::get_instance()->operator[](i);

		std::cout << student->get_name() << std::endl;
		std::cout << staff->get_name() << std::endl;
		std::cout << course->get_name() << std::endl;
		std::cout << room->get_id() << std::endl;

		StudentList::get_instance()->remove(student);
		std::cout << student->get_name() << std::endl;
		StaffList::get_instance()->remove(staff);
		CourseList::get_instance()->remove(course);
		RoomList::get_instance()->remove(room);

		delete student;
		delete staff;
		delete course;
		delete room;
	}
}

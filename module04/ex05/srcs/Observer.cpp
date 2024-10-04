#include <Observer.hpp>

Observer::Observer(Classroom *room): _room(room), _ringBell(false) {}

void	Observer::executeEvent(Event event, Headmaster* headmaster) {
	if (!headmaster || !this->_room) {
		return ;
    }
    Course* course = this->_room->getCurrentCourse();
	if (event == RingBell && course) {
        std::cout << "Bell is ringing!\n";
		Professor *professor = course->getCourseResponsable();
		std::vector<Student*> students = course->getCourseStudents();
        Room *room =static_cast<Room*>(this->_room);
		if (this->_ringBell){
            if (professor) {
                professor->exitClass(room);
            }
            std::vector<Student*>::iterator it = students.begin();
            for (; it != students.end(); ++it) {
				if ((*it)->room() == this->_room) {
                    (*it)->exitClass(room);
                }
            }
			this->_ringBell = false;
            room->printOccupant();
		} else {
			if (professor) {
                professor->enterClass(room);
            }
			std::vector<Student*>::iterator it = students.begin();
            for (; it != students.end(); ++it) {
                (*it)->attendClass(course, room);
            }
			this->_ringBell = true;
            room->printOccupant();
		}
	}
}

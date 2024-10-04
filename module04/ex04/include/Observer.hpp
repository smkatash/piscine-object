#pragma once

#include "Event.hpp"
#include "Room.hpp"
#include "Headmaster.hpp"

class Headmaster;
class Observer {
private:
	Classroom           *_room;
	bool 				_ringBell;
public:
	Observer(Classroom *room);
	void	executeEvent(Event event, Headmaster* headmaster);
};

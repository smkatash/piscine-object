#ifndef ROOMLIST_HPP
#define ROOMLIST_HPP
#include "Singleton.hpp"
#include "Room.hpp"

class RoomList : public SingletonObject<Room *> {
};

#endif

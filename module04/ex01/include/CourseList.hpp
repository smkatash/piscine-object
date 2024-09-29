#ifndef COURSELIST_HPP
#define COURSELIST_HPP
#include "Singleton.hpp"
#include "Course.hpp"

class CourseList : public SingletonObject<Course *> {
};

#endif

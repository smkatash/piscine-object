#pragma once
#include "Singleton.hpp"
#include "Course.hpp"

class CourseList : public SingletonObject<Course *> {
};

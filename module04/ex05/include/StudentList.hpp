#pragma once
#include "Singleton.hpp"
#include "Student.hpp"

class StudentList : public SingletonObject<Student *> {
};

#ifndef STUDENTLIST_HPP
#define STUDENTLIST_HPP
#include "Singleton.hpp"
#include "Student.hpp"

class StudentList : public SingletonObject<Student *> {
};

#endif

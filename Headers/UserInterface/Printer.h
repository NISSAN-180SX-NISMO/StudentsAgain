#pragma once
#include <iostream>
#include "../Entities/Student.h"

class Printer {
public:
    static void print (Student, std::ostream* out = &std::cout);
    static void print (myVector<Student>, std::ostream* out = &std::cout);
};

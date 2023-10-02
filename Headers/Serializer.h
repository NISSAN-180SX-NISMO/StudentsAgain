//
// Created by user on 02.10.2023.
//

#pragma once
#ifndef STUDENTMANAGER_SERIALIZER_H
#define STUDENTMANAGER_SERIALIZER_H

#include <fstream>
#include "Student.h"

class Serializer {
private:
    std::string file;
    void saveStudent(Student);
public:
    Serializer(std::string file); // без расширения
    ~Serializer() = default;
    void save(myVector<Student>);
    myVector<Student> load();
};


#endif //STUDENTMANAGER_SERIALIZER_H

#include "../../Headers/DataBase/StudentsDataBase.h"
#include <iostream>


void mydb::StudentsDataBase::add(Student student) {
    this->insideDataBase.push_back(student);
}


void mydb::StudentsDataBase::del(int index) {
this->insideDataBase.erase(index);
}


void mydb::StudentsDataBase::edit(int index, Student student) {
    this->insideDataBase.insert(index, student);
}


Student& mydb::StudentsDataBase::get(int index) {
    return this->insideDataBase[index];
}

std::pair<Student, int>* mydb::StudentsDataBase::get(std::function<bool(Student)> filter) {
    for (int i = 0; i < insideDataBase.size(); ++i)
        if (filter(insideDataBase[i]))
            return new std::pair<Student, int>(insideDataBase[i],i);
    return nullptr;
}

myVector<std::pair<Student, int>> mydb::StudentsDataBase::getAll(std::function<bool(Student)> filter) {
    myVector<std::pair<Student, int>> temp;
    for (int i = 0; i < insideDataBase.size(); ++i)
        if (filter(insideDataBase[i]))
            temp.push_back(std::pair<Student, int>(insideDataBase[i],i));
    return temp;
}

myVector<Student> mydb::StudentsDataBase::getAllRaw()
{
    myVector<Student> temp;
    for (int i = 0; i < insideDataBase.size(); ++i)
            temp.push_back(insideDataBase[i]);
    return temp;
}


void mydb::StudentsDataBase::saveToFile() {
    std::ofstream out("save.txt");
    for (int i = 0; i < insideDataBase.size(); ++i)
            insideDataBase[i].save(out);
    out.close();
}


void mydb::StudentsDataBase::loadFromFile() {
    std::ifstream in("save.txt");
    std::string buff;
    while (getline(in, buff))
        add(Student::load(buff));
    in.close();
}

myVector<Student> mydb::StudentsDataBase::sort(myVector<Student> students, std::function<bool(Student, Student)> filter)
{
    myVector<Student> sorted = students;
    for (int i = 0; i < sorted.size() - 1; i++) {
        for (int j = 0; j < sorted.size() - i - 1; j++) {
            if (filter(sorted[j], sorted[j + 1])) {
                // если текущий больше следующего, мен¤ем их местами
                auto temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    return sorted;
}



mydb::StudentsDataBase::StudentsDataBase() {
    loadFromFile();
}


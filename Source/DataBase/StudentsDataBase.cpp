#include "../../Headers/StudentsDataBase.h"


void mydb::StudentsDataBase::add(Student student) {
    this->insideDataBase.push_back(student);
}


void mydb::StudentsDataBase::del(int index) {
this->insideDataBase.erase(index);
}


void mydb::StudentsDataBase::edit(int index, Student student) {
    this->insideDataBase.insert(index, student);
}


Student mydb::StudentsDataBase::get(int index) {
    return this->insideDataBase[index];
}


myVector<Student> mydb::StudentsDataBase::getAll(bool filter) {
    myVector<Student> temp;
    for (int i = 0; i < insideDataBase.size(); ++i)
        if (filter)  temp.push_back(insideDataBase[i]);
    return temp;
}


void mydb::StudentsDataBase::sort(bool filter) {
    // TODO
}



void mydb::StudentsDataBase::saveToFile() {
    std::ofstream out(filename);
    for (int i = 0; i < insideDataBase.size(); ++i)
        insideDataBase[i].save(out);
}


void mydb::StudentsDataBase::loadToFile() {
    std::ifstream in(filename);
    std::string buff;
    while (getline(in, buff))
        add(Student::load(buff));
}


mydb::StudentsDataBase::StudentsDataBase() = default;


#include "../../Headers/StudentsDataBase.h"

template<class value>
void mydb::StudentsDataBase<value>::add(Student student) {
    this->insideDataBase.push_back(student);
}

template<class value>
void mydb::StudentsDataBase<value>::del(int index) {
this->insideDataBase.erase(this->insideDataBase.begin() + index);
}

template<class value>
void mydb::StudentsDataBase<value>::edit(int index, Student student) {
    this->insideDataBase.insert(this->insideDataBase.begin() + index, student);
}

template<class value>
Student mydb::StudentsDataBase<value>::get(int index) {
    return this->insideDataBase[index];
}

template<class value>
std::vector<Student> mydb::StudentsDataBase<value>::getAll(int index, bool filter) {
    std::vector<Student> filteredOutput;
    for (auto student: this->insideDataBase)
        if (filter) filteredOutput.push_back(student);
    return filteredOutput;
}

template<class value>
void mydb::StudentsDataBase<value>::sort(bool filter) {
    // TODO
}

//
// Created by user on 02.10.2023.
//

#include "../../Headers/Serializer.h"

Serializer::Serializer(std::string file) {
    this->file = "../../" + file + ".txt";

}

void Serializer::saveStudent(Student student) {
    std::ofstream out(file, std::ofstream::app);
    out.write((char*)&student, sizeof(Student));
    out.close();
}


void Serializer::save(myVector<Student> students) {
    for (int i = 0; i < students.size(); ++i)
        saveStudent(students[i]);
}

myVector<Student> Serializer::load() {
    myVector<Student> output;
    std::ifstream in(file);
    Student temp;
    while (in.read((char*)&temp, sizeof(Student)))
        output.push_back(temp);
    in.close();
    return output;
}

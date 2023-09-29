#ifndef STUDENTMANAGER_STUDENT_H
#define STUDENTMANAGER_STUDENT_H

#include <string>
#include <vector>


class Student {
private:
    std::string idCard; // primary key
    std::string groupNumber;
    std::string fullName;
    std::vector<int> marks;
public:
    const std::string &getIdCard() const;
    void setIdCard(const std::string &idCard);
    const std::string &getGroupNumber() const;
    void setGroupNumber(const std::string &groupNumber);
    const std::string &getFullName() const;
    void setFullName(const std::string &fullName);
    void setMark(int mark);
};

#endif //STUDENTMANAGER_STUDENT_H

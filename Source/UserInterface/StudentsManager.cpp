#include "../../Headers/UserInterface/StudentsManager.h"

StudentsDataBaseController StudentsManager::controller = StudentsDataBaseController();

void StudentsManager::addStudent() {
    std::string surname =       input("������� ������� ��������: ", FORMAT::SURNAME),
                name =          input("������� ��� ��������: ", FORMAT::NAME),
                patronymic =    input("������� �������� ��������: ", FORMAT::PATRONYMIC),
                groupNumber =   input("������� ����� ������: ", FORMAT::GROUP_NUMBER),
                idCard =        input("������� ����� ������������� ������: ", FORMAT::ID_CARD),
                AverageMark =   input("������� ������� ���� (��� ������� \"0\" ���� ������ �� ����): ", FORMAT::AVERAGE_MARK);
    if (controller.addStudent(surname + " " + name + " " + patronymic, groupNumber, idCard, AverageMark))
        std::cout << "������� ������� ��������!" << std::endl;
    else std::cout << "������! ����� ������� ��� ����!" << std::endl;
    pause();
}

void StudentsManager::deleteStudent() {
    std::string idCard = input("������� ����� ������������� ������ ���������� ��������: ", FORMAT::ID_CARD);
    if (controller.deleteStudent(idCard)) std::cout << "������� ������� ������!" << std::endl;
    else std::cout << "������! ������ �������� �� ����������!" << std::endl;
    pause();
}

void StudentsManager::editStudent() {
    std::string idCard = input("������� ����� ������������� ������ ���������� ��������: ", FORMAT::ID_CARD);
    auto student = controller.findStdent(idCard);
    if (!student) {
        std::cout << "������! ������� �� ������!" << std::endl;
        return;
    }
    Printer::print(student->first);
    std::cout << "������� ����� �������� ��� ������ ��� ���������� �����:" << std::endl;
    std::string newSurname =       input("������� ������� ��������: ", FORMAT::SURNAME),
            newName =          input("������� ��� ��������: ", FORMAT::NAME),
            newPatronymic =    input("������� �������� ��������: ", FORMAT::PATRONYMIC),
            newGroupNumber =   input("������� ����� ������: ", FORMAT::GROUP_NUMBER),
            newIdCard =        input("������� ����� ������������� ������: ", FORMAT::ID_CARD);
    controller.editStudent(student->second,  + " " + newName + " " + newPatronymic, newGroupNumber, newIdCard);
    pause();
}

void StudentsManager::findStudentByFullname() {
    std::string fullName = input("������� ������� ��������: ", FORMAT::NONE);
    auto students = controller.getStudents([fullName](Student student) {
        return student.getFullName() == fullName;
        });
    if (students.size() == 0)
        std::cout << "�������� � ����� ��� � �������" << std::endl;
    else {
        std::cout << "��������� ��������:" << std::endl;
        Printer::print(students);
    }
    pause();
}

void StudentsManager::findStudentByGroupNumber() {
    pause();
}

void StudentsManager::findStudentByIdCard_Match() {
    pause();
}

void StudentsManager::findStudentByIdCard_Between() {
    pause();
}

void StudentsManager::printStudents(SORT flag) {
    if (flag == SORT::NONE)
        Printer::print(controller.getStudents());
    else if (flag == SORT::FULLNAME) {
        Printer::print(controller.sort([](Student first, Student second) {
            return first.getFullName() > second.getFullName();
            }));
    }
    else if(flag == SORT::GROUP_NUMBER)
        Printer::print(controller.sort([](Student first, Student second) {
        return first.getGroupNumber() > second.getGroupNumber();
            }));
    else if(flag == SORT::ID_CARD)
        Printer::print(controller.sort([](Student first, Student second) {
        return first.getIdCard() > second.getIdCard();
            }));
    pause();
}

void StudentsManager::loadStudentsFromFile() {
    pause();
}

void StudentsManager::saveAndExit() {
    controller.saveToFile();
    std::cout << "������ ���������" << std::endl;
    exit(0);
}

std::string StudentsManager::input(const std::string& title, FORMAT format) {
    while (true) {
        std::string input;
        std::cout << title;
        getline(std::cin, input);
        Validator inputValidator(input);
        if (inputValidator(format)) return input;
        std::cout << "Format Error! Repeat the input please!" << std::endl;
    }
}

void StudentsManager::pause()
{
    std::cout << "������� ����� ������� ��� �����������..." << std::endl;
    _getch();
}

void StudentsManager::putMark() {
    pause();
}




#include "../Headers/UserInterface/StudentsManager.h"
#include "../Headers/Menu/Menu.h"
#include <Windows.h>

int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Menu mainMenu;
    Menu* findStudentMenu = new Menu();
    Menu* findStudentMenuByName = new Menu();
    Menu* findStudentByIdCardMenu = new Menu();
    Menu* printStudentsMenu = new Menu();

    mainMenu.push_case("[1] = �������� ��������",          KEY::ONE,  StudentsManager::addStudent);
    mainMenu.push_case("[2] = ������� �������� �� ������", KEY::TWO,  StudentsManager::deleteStudent);
    mainMenu.push_case("[3] = �������� ������ � ��������", KEY::THREE,StudentsManager::editStudent);
    mainMenu.push_case("[4] = ����� ��������...",          KEY::FOUR,findStudentMenu);
    findStudentMenu->push_case("[1] = ������ �� ���", KEY::ONE, findStudentMenuByName);
    findStudentMenuByName->push_case("[1] = ����� � ������ �����������",    KEY::ONE, [](){StudentsManager::findStudentByFullname(1);});
    findStudentMenuByName->push_case("[2] = ����� � �������� �����������",  KEY::TWO, [](){StudentsManager::findStudentByFullname(0.57);});
    findStudentMenu->push_case("[2] = ������ �� ������ ������", KEY::TWO, StudentsManager::findStudentByGroupNumber);
    findStudentMenu->push_case("[3] = ������ �� �������� �����...",  KEY::THREE,    findStudentByIdCardMenu);
    findStudentByIdCardMenu->push_case("[1] = ����� �� ��������� ��������", KEY::ONE, StudentsManager::findStudentByIdCard_Match);
    findStudentByIdCardMenu->push_case("[2] = ����� ����� ����� ����������", KEY::TWO, StudentsManager::findStudentByIdCard_Between);
    mainMenu.push_case("[5] = ������� ������ ���������...", KEY::FIVE, printStudentsMenu);
    printStudentsMenu->push_case("[1] = ������� ��� ����������",            KEY::ONE,   [](){StudentsManager::printStudents(StudentsManager::SORT::NONE);});
    printStudentsMenu->push_case("[2] = ���������� �� ��������",            KEY::TWO,   [](){StudentsManager::printStudents(StudentsManager::SORT::FULLNAME);});
    printStudentsMenu->push_case("[3] = ���������� �� ������ ������",       KEY::THREE, [](){StudentsManager::printStudents(StudentsManager::SORT::GROUP_NUMBER);});
    printStudentsMenu->push_case("[4] = ���������� �� ������ �������������",KEY::FOUR,  [](){StudentsManager::printStudents(StudentsManager::SORT::ID_CARD);});
    printStudentsMenu->push_case("[5] = ���������� �� �������� �����",      KEY::FIVE,  [](){StudentsManager::printStudents(StudentsManager::SORT::AVERAGE_MARK);});
    mainMenu.push_case("[6] = ��������� ������", KEY::SIX, StudentsManager::putMark);
    mainMenu.push_case("[0] = ���������� � �����", KEY::ZERO, StudentsManager::saveAndExit);

    mainMenu.start();

    system("pause");

}
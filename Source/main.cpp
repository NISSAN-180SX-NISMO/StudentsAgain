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

    mainMenu.push_case("[1] = Добавить студента",          KEY::ONE,  StudentsManager::addStudent);
    mainMenu.push_case("[2] = Удалить студента из списка", KEY::TWO,  StudentsManager::deleteStudent);
    mainMenu.push_case("[3] = Изменить данные о студенте", KEY::THREE,StudentsManager::editStudent);
    mainMenu.push_case("[4] = Поиск студента...",          KEY::FOUR,findStudentMenu);
    findStudentMenu->push_case("[1] = Искать по ФИО", KEY::ONE, findStudentMenuByName);
    findStudentMenuByName->push_case("[1] = Поиск с полным совпадением",    KEY::ONE, [](){StudentsManager::findStudentByFullname(1);});
    findStudentMenuByName->push_case("[2] = Поиск с неполным совпадением",  KEY::TWO, [](){StudentsManager::findStudentByFullname(0.57);});
    findStudentMenu->push_case("[2] = Искать по номеру группы", KEY::TWO, StudentsManager::findStudentByGroupNumber);
    findStudentMenu->push_case("[3] = Искать по среднему баллу...",  KEY::THREE,    findStudentByIdCardMenu);
    findStudentByIdCardMenu->push_case("[1] = Поиск по заданному значению", KEY::ONE, StudentsManager::findStudentByIdCard_Match);
    findStudentByIdCardMenu->push_case("[2] = Поиск между двумя значениями", KEY::TWO, StudentsManager::findStudentByIdCard_Between);
    mainMenu.push_case("[5] = Вывести список студентов...", KEY::FIVE, printStudentsMenu);
    printStudentsMenu->push_case("[1] = Вывести без сортировки",            KEY::ONE,   [](){StudentsManager::printStudents(StudentsManager::SORT::NONE);});
    printStudentsMenu->push_case("[2] = Сортировка по алфавиту",            KEY::TWO,   [](){StudentsManager::printStudents(StudentsManager::SORT::FULLNAME);});
    printStudentsMenu->push_case("[3] = Сортировка по номеру группы",       KEY::THREE, [](){StudentsManager::printStudents(StudentsManager::SORT::GROUP_NUMBER);});
    printStudentsMenu->push_case("[4] = Сортировка по номеру студенческого",KEY::FOUR,  [](){StudentsManager::printStudents(StudentsManager::SORT::ID_CARD);});
    printStudentsMenu->push_case("[5] = Сортировка по среднему баллу",      KEY::FIVE,  [](){StudentsManager::printStudents(StudentsManager::SORT::AVERAGE_MARK);});
    mainMenu.push_case("[6] = Поставить оценку", KEY::SIX, StudentsManager::putMark);
    mainMenu.push_case("[0] = Сохранение и выход", KEY::ZERO, StudentsManager::saveAndExit);

    mainMenu.start();

    system("pause");

}
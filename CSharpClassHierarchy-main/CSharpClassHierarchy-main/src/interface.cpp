#include <iostream>
#include <exception>

#include "CSharpHierarchy.h"

// Функция примера
void sample(CSharpHierarchy& cSharpHierarchy) {
    // Создание пространства имен "A"
    cSharpHierarchy.createNamespace("A");

    // Создание класса "FirstParentClass" с полями и методами
    std::vector<CSharpField> fields1;
    fields1.emplace_back("int a = 1;");
    fields1.emplace_back("int b = 2;");
    std::vector<CSharpMethod> methods1;
    methods1.emplace_back("void firstParentMethodOne();");
    methods1.emplace_back("void firstParentMethodTwo();");
    cSharpHierarchy.createClass("FirstParentClass", fields1, methods1, TYPE::BASE);
    cSharpHierarchy.addClassToNamespace("FirstParentClass", "A");

    // Создание класса "SecondParentClass" с полями и методами
    std::vector<CSharpField> fields2;
    fields2.emplace_back("int c = 3;");
    fields2.emplace_back("int d = 4;");
    std::vector<CSharpMethod> methods2;
    methods2.emplace_back("void secondParentMethodOne();");
    methods2.emplace_back("void secondParentMethodTwo();");
    cSharpHierarchy.createClass("SecondParentClass", fields2, methods2, TYPE::BASE);
    cSharpHierarchy.addClassToNamespace("SecondParentClass", "A");

    // Создание класса "ChildClass" с полями и методами, и указание родителя
    std::vector<CSharpField> fields3;
    fields3.emplace_back("int e = 5;");
    fields3.emplace_back("int f = 6;");
    std::vector<CSharpMethod> methods3;
    methods3.emplace_back("void childMethod();");
    methods3.emplace_back("void childMethod();");
    cSharpHierarchy.createClass("ChildClass", fields3, methods3, TYPE::BASE);
    cSharpHierarchy.getClassByName("ChildClass")
            .setParentClass(cSharpHierarchy.getClassByName("SecondParentClass"));
    cSharpHierarchy.addClassToNamespace("ChildClass", "A");

    // Вывод пространства имен "A" на экран
    std::cout << cSharpHierarchy.getNamespaceByName("A").toString() << std::endl;
}

// Функция для ввода типа класса
TYPE inputType() {
    char userChoice;
    TYPE type;
    std::cout << "Input csharpClassType a - abstruct, b - base, d - derived" << std::endl;
    std::cin >> userChoice;
    if (userChoice == 'a') {
        type = TYPE::ABSTRACT;
    } else if (userChoice == 'b') {
        type = TYPE::BASE;
    } else if (userChoice == 'd') {
        type == TYPE::DERIVED; // Ошибка: должно быть "=" вместо "=="
    } else {
        std::cout << "Error!" << std::endl;
    }
    return type;
}

// Функция для ввода полей класса
std::vector<CSharpField> inputClassFields() {
    char userChoice;
    std::string field;
    std::vector<CSharpField> fields;
    while (true) {
        std::cout << "Input fields? y/n" << std::endl;
        std::cin >> userChoice;
        if (userChoice == 'y') {
            std::cout << "Input field" << std::endl;
            while (std::getline(std::cin, field)) {
                if (!field.empty()) {
                    break;
                }
            }
            fields.emplace_back(field);
        } else if (userChoice == 'n' && !fields.empty()) {
            break;
        } else {
            std::cout << "Input mismatch" << std::endl;
            break;
        }
    }
    return fields;
}

// Функция для ввода методов класса
std::vector<CSharpMethod> inputClassMethods() {
    char userChoice;
    std::string method;
    std::vector<CSharpMethod> methods;
    while (true) {
        std::cout << "Input methods? y/n" << std::endl;
        std::cin >> userChoice;
        if (userChoice == 'y') {
            std::cout << "Input method" << std::endl;
            while (std::getline(std::cin, method)) {
                if (!method.empty()) {
                    break;
                }
            }
            methods.emplace_back(method);
        } else if (userChoice == 'n' && !methods.empty()) {
            break;
        } else {
            std::cout << "Input mismatch" << std::endl;
            break;
        }
    }
    return methods;
}

// Функция для выбора родительского класса
CSharpClass inputParents(const std::vector<CSharpClass> classes) {
    CSharpClass parentClass;
    char userChoice;
    if (classes.size() > 1) {
        std::cout << "Has parent class? y/n";
        std::cin >> userChoice;
        if (userChoice == 'y') {
            std::string parent_class_name;
            std::cout << "Type class name" << std::endl;
            while (std::getline(std::cin, parent_class_name)) {
                if (!parent_class_name.empty()) { break; }
            }
            for (CSharpClass cls : classes) {
                if (cls.getClassName() == parent_class_name) {
                    parentClass = cls;
                }
            }
        }
    }
    return parentClass;
}

// Функция для выбора действия из меню
int menu() {
    int userChoice;
    std::cout << "Choose action:\n"
                 "1 - Create namespace\n"
                 "2 - Create new class\n"
                 "3 - Update class\n"
                 "4 - Update namespace\n"
                 "5 - Delete class\n"
                 "6 - Delete namespace\n"
                 "7 - Show all classes\n"
                 "8 - Show all namespaces with its classes" << std::endl;
    std::cin >> userChoice;
    return userChoice;
}

// Функция для создания нового класса
void createClass(CSharpHierarchy& cSharpHierarchy) {
    // Поля класса CSharpClass
    std::string className;
    std::string field;
    std::string method;
    // Ввод имени класса
    std::cout << "Input class name" << std::endl;
    std::cin >> className;
    // Ввод типа класса
    TYPE type = inputType();
    // Ввод полей класса
    std::vector<CSharpField> fields = inputClassFields();
    // Ввод методов класса
    std::vector<CSharpMethod> methods = inputClassMethods();
    // Создание класса
    cSharpHierarchy.createClass(className, fields, methods, type);
    // Ввод родительского класса
    CSharpClass parent = inputParents(cSharpHierarchy.getClasses());
    cSharpHierarchy.addParents(cSharpHierarchy.getClassByName(className), parent.getClassName());
    // Добавление класса в пространство имен
    if (cSharpHierarchy.getNamespaces().size() >= 1) {
        std::cout << "Would you like to add this class to namespace? y/n" << std::endl;
        std::string namespaceName;
        std::cin >> namespaceName;
        if (namespaceName == "y") {
            while (true) {
                std::cout << "Input namespace name or type \"stop\" for cancel """ << std::endl;
                std::cin >> namespaceName;
                if (namespaceName == "stop") {
                    break;
                }
                cSharpHierarchy.addClassToNamespace(className, namespaceName);
                break;
            }
        }
    }
    std::cout << "Class created!" << std::endl;
}

// Функция для создания нового пространства имен
void createNamespace(CSharpHierarchy& cSharpHierarchy) {
    std::string namespaceName;
    std::cout << "Input namespace name" << std::endl;
    std::cin >> namespaceName;
    cSharpHierarchy.createNamespace(namespaceName);
    std::cout << "Completed!" << std::endl;
}

// Функция для обновления класса
void updateClass(CSharpHierarchy &cSharpHierarchy) {
    std::string className;
    std::string newClassName;
    CSharpField field;
    CSharpMethod method;
    std::cout << "Input classname" << std::endl;
    std::cin >> className;
    std::cout << "Input new classname" << std::endl;
    std::cin >> newClassName;
    std::vector<CSharpField> fields = inputClassFields();
    std::vector<CSharpMethod> methods = inputClassMethods();
    std::cout << "Input parent" << std::endl;
    CSharpClass parent = inputParents(cSharpHierarchy.getClasses());
    cSharpHierarchy.addParents(cSharpHierarchy.getClassByName(className), parent.getClassName());
    try {
        // Обновление класса
        cSharpHierarchy.updateClassByName(className, newClassName, fields, methods, parent);
    } catch (std::exception e) {
        std::cout << "No such class" << std::endl;
    }
}

// Функция для обновления пространства имен
void updateNamespace(CSharpHierarchy &cSharpHierarchy) {
    std::string namespaceName;
    std::string newNamespaceName;
    std::cout << "Input namespace name" << std::endl;
    std::cin >> namespaceName;
    std::cout << "Input namespace name" << std::endl;
    std::cin >> newNamespaceName;
    try {
        // Обновление пространства имен
        cSharpHierarchy.updateNamespaceByName(namespaceName, newNamespaceName);
    } catch (std::exception e) {
        std::cout << "No such namespace" << std::endl;
    }
}

// Функция для удаления класса
void deleteClass(CSharpHierarchy &cSharpHierarchy) {
    std::string className;
    std::cout << "Input class name" << std::endl;
    std::cin >> className;
    try {
        // Удаление класса
        cSharpHierarchy.deleteClassByName(className);
    } catch(const std::exception e) {
        std::cout << "No such class" << std::endl;
    }
}

// Функция для удаления пространства имен
void deleteNamespace(CSharpHierarchy &cSharpHierarchy) {
    std::string namespaceName;
    std::cout << "Input naspaceName name" << std::endl;
    std::cin >> namespaceName;
    try {
        // Удаление пространства имен
        cSharpHierarchy.deleteNamespaceByName(namespaceName);
    } catch(const std::exception e) {
        std::cout << "No such namespace" << std::endl;
    }
}

// Функция для взаимодействия с пользователем
void userInput(CSharpHierarchy& cSharpHierarchy) {
    while (true) {
        int userChoice = menu();
        switch (userChoice) {
            case 1: {
                createNamespace(cSharpHierarchy);
                break;
            }
            case 2: {
                createClass(cSharpHierarchy);
                break;
            }
            case 3: {
                updateClass(cSharpHierarchy);
                break;
            }
            case 4: {
                updateNamespace(cSharpHierarchy);
                break;
            }
            case 5: {
                deleteClass(cSharpHierarchy);
                break;
            }
            case 6: {
                deleteNamespace(cSharpHierarchy);
                break;
            }
            case 7: {
                std::cout << cSharpHierarchy.classesToString() << std::endl;
                break;
            }
            case 8: {
                std::cout << cSharpHierarchy.namespacesToString() << std::endl;
                break;
            }
            default: {
                std::cout << "Mismatch input" << std::endl;
                break;
            }
        }
    }
}

// Главная функция
int main() {
    // Создание иерархии классов
    CSharpHierarchy cSharpHierarchy;
    // Выбор действия пользователем
    std::cout << "1 - Sample\n2- User input\n" << std::endl;
    int user_choice = 0;
    std::cin >> user_choice;
    switch (user_choice) {
        case 1:
            sample(cSharpHierarchy);
            break;
        case 2:
            userInput(cSharpHierarchy);
            break;
        default:
            break;
    }
    return 0;
}

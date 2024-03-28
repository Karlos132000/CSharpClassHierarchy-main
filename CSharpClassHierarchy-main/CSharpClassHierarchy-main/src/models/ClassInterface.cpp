#include <iostream>
#include <vector>
#include <memory>

// Интерфейс класса "Class"
class Class {
public:
    virtual ~Class() = default;

    // Метод для проверки корректности класса
    virtual bool isValid() const = 0;

    // Метод для получения имени класса
    virtual std::string getName() const = 0;
};

// Реализация обычного класса
class RegularClass : public Class {
private:
    std::string name;

public:
    // Конструктор с именем класса
    explicit RegularClass(const std::string& name) : name(name) {}

    // Переопределение метода для проверки корректности класса
    bool isValid() const override {
        // Обычный класс всегда считается корректным
        return true;
    }

    // Переопределение метода для получения имени класса
    std::string getName() const override {
        return name;
    }
};

// Реализация абстрактного класса
class AbstractClass : public Class {
private:
    std::string name;

public:
    // Конструктор с именем класса
    explicit AbstractClass(const std::string& name) : name(name) {}

    // Переопределение метода для проверки корректности класса
    bool isValid() const override {
        // Абстрактный класс считается корректным, если не переопределен
        return false;
    }

    // Переопределение метода для получения имени класса
    std::string getName() const override {
        return name;
    }
};

// Функция для проверки корректности класса
bool checkClassValidity(const Class& cls) {
    return cls.isValid();
}



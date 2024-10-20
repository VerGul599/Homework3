#include <iostream>
#include <string>

// Базовый класс Растение
class Plant 
{
protected:
    std::string name; // Название
    std::string size; // Размер 
    double height;    // Высота

public:
    // Конструктор
    Plant(std::string n, std::string s, double h) : name(n), size(s), height(h) {}

    // Метод для получения информации о растении
    virtual void displayInfo() const
    {
        std::cout << "Название: " << name << "\nРазмер: " << size << "\nВысота: " << height << " м \n\n";
    }
};

// Класс Куст
class Bush : public Plant
{
public:
    // Конструктор
    Bush(std::string n, double h) : Plant(n, "маленькое", h) {}

    // Переопределение метода для отображения информации о кусте
    void displayInfo() const override
    {
        std::cout << "Куст \n\n" ;
        Plant::displayInfo();
    }

    // Метод для сбора плодов (ягод)
    void collectFruits() const
    {
        std::cout << "Собраны ягоды: Малина, Клубника \n\n";
    }
};

// Класс Дерево
class Tree : public Plant 
{
public:
    // Конструктор
    Tree(std::string n, double h) : Plant(n, "большое", h) {}

    // Переопределение метода для отображения информации о дереве
    void displayInfo() const override 
    {
        std::cout << "Дерево \n\n";
        Plant::displayInfo();
    }

    // Метод для сбора плодов (фруктов)
    void collectFruits() const 
    {
        std::cout << "Собраны фрукты: Яблоко, Груша \n";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian"); 

    // Создание объектов кустов и деревьев
    Bush bush("Малиновый куст", 1.5);
    Tree tree("Яблоня", 3.0);

    // Отображение информации о растениях
    bush.displayInfo();
    tree.displayInfo();

    // Сбор плодов
    bush.collectFruits();
    tree.collectFruits();

    return 0;
}

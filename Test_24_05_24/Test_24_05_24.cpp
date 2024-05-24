#include <iostream>
#include "windows.h"
using namespace std;

const float PI = 3.141592654;

class Student {
    string name;
    int age;
    float averageScore;
public:
    Student() : name(""), age(0), averageScore(0) {}
    Student(string n, int a, float s) : name(n), age(a), averageScore(s) {}
    string getName() const { return name; }
    int getAge() const { return age; }
    float getAverageScore() const { return averageScore; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setAverageScore(float s) { averageScore = s; }
    void showInfo() {
        cout << "Інформація про студента:" << endl;
        cout << "Ім'я: \"" << name << "\":" << endl;
        cout << "Вік: " << age << endl;
        cout << "Середній бал: " << averageScore << endl;
        cout << endl;
    }
};

class Triangle {
    int a;
    int b;
    int c;
public:
    Triangle(int aa, int bb, int cc) {
        c = max(max(aa, bb), cc);
        a = min(min(aa, bb), cc);
        b = aa + bb + cc - a - c;
    }
    bool isRight() {
        return a * a + b * b == c * c;
    }
    int getPerimeter() {
        return a + b + c;
    }
    float getArea() {
        float p = (a + b + c) * 0.5;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Figure {
    string color;
public:
    Figure() : color("") {}
    Figure(string c) : color(c) {}
    string getColor() { return color; }
};

class Circle : public Figure {
    float radius;
public:
    Circle() : Figure(), radius(0) {}
    Circle(string c, float r) : Figure(c), radius(r) {}
    float getPerimeter() { return 2*PI*radius; }
    float getArea() { return PI * radius*radius; }
};

class Rect : public Figure {
    float a;
    float b;
public:
    Rect() : Figure(), a(0), b(0) {}
    Rect(string c, float aa, float bb) : Figure(c), a(aa), b(bb) {}
    float getPerimeter() { return 2 * (a + b); }
    float getArea() { return a * b; }
};

class Triang : public Figure {
    float a;
    float b;
    float c;
public:
    Triang() : Figure(), a(0), b(0), c(0) {}
    Triang(string col, float aa, float bb, float cc) : Figure(col) {
        c = max(max(aa, bb), cc);
        a = min(min(aa, bb), cc);
        b = aa + bb + cc - a - c;
    }
    float getPerimeter() { return a + b + c; }
    float getArea() { 
        float p = (a + b + c) * 0.5;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Vehicle {
    float power;
    float speed;
public:
    Vehicle() : power(0), speed(0) {}
    Vehicle(float p, float s) : power(p), speed(s) {}
    float getPower() { return power; }
    float getSpeed() { return speed; }
};

class Car : public Vehicle {
public:
    Car() : Vehicle() {}
    Car(float p, float s) : Vehicle(p, s) {}
    float getMaxCapacity() { return getPower() * 5; }
};

class Truck : public Vehicle {
public:
    Truck() : Vehicle() {}
    Truck(float p, float s) : Vehicle(p, s) {}
    float getMaxCapacity() { return getPower() * 20; }
};

class Bike : public Vehicle {
public:
    Bike() : Vehicle() {}
    Bike(float p, float s) : Vehicle(p, s) {}
    float getMaxCapacity() { return getPower(); }
};



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Інкапсуляція" << endl;
    cout << "1. Створіть клас \"Студент\", який містить наступні атрибути: ім'я, вік, середній бал." << endl;
    cout << "Реалізуйте методи для встановлення та отримання значень кожного атрибута, а також метод для виведення інформації про студента." << endl;

    Student student = Student();
    cout << "Введіть ім'я студента: ";
    string name;
    cin >> name;
    student.setName(name);
    cout << "Ім'я студента: " << student.getName() << endl;
    cout << "Введіть вік студента: ";
    int age;
    cin >> age;
    student.setAge(age);
    cout << "Вік студента: " << student.getAge() << endl;
    cout << "Введіть середній бал студента: ";
    float averageScore;
    cin >> averageScore;
    student.setAverageScore(averageScore);
    cout << "Середній бал студента: " << student.getAverageScore() << endl;
    student.showInfo();

    cout << "2. Створіть клас \"Трикутник\", який містить атрибути для зберігання довжин сторін." << endl;
    cout << "Реалізуйте методи для обчислення периметра і площі трикутника, а також метод для перевірки, чи є трикутник прямокутним." << endl;

    int a, b, c;
    cout << "Введіть довжину 1-ї сторони трикутника: ";
    cin >> a;
    cout << "Введіть довжину 2-ї сторони трикутника: ";
    cin >> b;
    cout << "Введіть довжину 3-ї сторони трикутника: ";
    cin >> c;
    Triangle triangle(a, b, c);
    cout << "Периметр трикутника: " << triangle.getPerimeter() << endl;
    cout << "Площа трикутника: " << triangle.getArea() << endl;
    string right = triangle.isRight() ? "" : "не ";
    cout << "Трикутник " << right << "є прямокутним" << endl;

    cout << "Наслідування" << endl;
    cout << "1. Створіть клас \"Фігура\", який має атрибут для кольору." << endl;
    cout << "Створіть підкласи, такі як \"Коло\", \"Прямокутник\" та \"Трикутник\", які наслідують клас \"Фігура\"." << endl;
    cout << "Кожен з підкласів повинен мати свої власні атрибути та методи, наприклад, для обчислення площі." << endl;

    cout << "Введіть колір фігури: ";
    string color;
    cin >> color;
    cout << "Введіть радіус кола: ";
    float radius;
    cin >> radius;
    Circle circle(color, radius);
    cout << "Площа кола: " << circle.getArea() << endl;
    cout << "Периметр кола: " << circle.getPerimeter() << endl;
    cout << "Колір кола: " << circle.getColor() << endl << endl;

    cout << "Введіть довжину 1-ї сторони прямокутника: ";
    cin >> a;
    cout << "Введіть довжину 2-ї сторони прямокутника: ";
    cin >> b;
    Rect rect(color, a, b);
    cout << "Площа прямокутника: " << rect.getArea() << endl;
    cout << "Периметр прямокутника: " << rect.getPerimeter() << endl;
    cout << "Колір прямокутника: " << rect.getColor() << endl << endl;

    cout << "Введіть довжину 1-ї сторони трикутника: ";
    cin >> a;
    cout << "Введіть довжину 2-ї сторони трикутника: ";
    cin >> b;
    cout << "Введіть довжину 3-ї сторони трикутника: ";
    cin >> c;
    Triang triang(color, a, b, c);
    cout << "Площа трикутника: " << triang.getArea() << endl;
    cout << "Периметр трикутника: " << triang.getPerimeter() << endl;
    cout << "Колір трикутника: " << triang.getColor() << endl << endl;

    cout << "Створіть клас \"Транспортний засіб\" з атрибутами, такими як швидкість та потужність двигуна." << endl;
    cout << "Створіть підкласи, такі як \"Легковий автомобіль\", \"Вантажівка\" та \"Мотоцикл\", які наслідують клас \"Транспортний засіб\"." << endl;
    cout << "Кожен з підкласів може мати власні методи, наприклад, для обчислення максимальної ваги, яку може перевозити." << endl;

    cout << "Введіть швидкість машини: ";
    float speed;
    cin >> speed;
    cout << "Введіть потужність двигуна машини: ";
    float power;
    cin >> power;
    Car car(power, speed);
    cout << "Максимальна вага, яку може перевозити машина: " << car.getMaxCapacity() << endl << endl;

    cout << "Введіть швидкість вантажівки: ";
    cin >> speed;
    cout << "Введіть потужність двигуна вантажівки: ";
    cin >> power;
    Truck truck(power, speed);
    cout << "Максимальна вага, яку може перевозити вантажівка: " << truck.getMaxCapacity() << endl << endl;

    cout << "Введіть швидкість мотоцикла: ";
    cin >> speed;
    cout << "Введіть потужність двигуна мотоцикла: ";
    cin >> power;
    Bike bike(power, speed);
    cout << "Максимальна вага, яку може перевозити мотоцикл: " << bike.getMaxCapacity() << endl << endl;
}
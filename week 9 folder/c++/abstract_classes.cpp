// ACTIVITY 3: ABSTRACT CLASSES AND PURE VIRTUAL FUNCTIONS
#include <iostream>
using namespace std;

class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() = default;
};

class Square : public Shape {
private:
    double side;

public:
    explicit Square(double s) : side(s) {}

    double calculateArea() const override {
        return side * side;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    // Shape myShape; // ERROR: Shape is abstract and cannot be instantiated.

    Square s(5.0);
    Circle c(3.0);

    cout << "Area of Square: " << s.calculateArea() << endl;
    cout << "Area of Circle: " << c.calculateArea() << endl;

    return 0;
}

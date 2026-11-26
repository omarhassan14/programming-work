// ACTIVITY 1: BASIC INHERITANCE
#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;

public:
    Shape(const string& c) : color(c) {
        cout << "Shape constructor called." << endl;
    }

    void displayColor() const {
        cout << "This shape's color is: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const string& c, double r) : Shape(c), radius(r) {
        cout << "Circle constructor called." << endl;
    }

    void displayCircleInfo() const {
        cout << "This circle is " << color
             << " and has a radius of " << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(const string& c, double w, double h)
        : Shape(c), width(w), height(h) {
        cout << "Rectangle constructor called." << endl;
    }

    void displayRectangleInfo() const {
        cout << "This rectangle is " << color
             << " and is " << width << "x" << height << endl;
    }
};

int main() {
    cout << "--- Creating a Circle ---" << endl;
    Circle myCircle("Red", 5.0);
    myCircle.displayColor();
    myCircle.displayCircleInfo();

    cout << "\n--- Creating a Rectangle ---" << endl;
    Rectangle myRect("Blue", 4.0, 6.0);
    myRect.displayColor();
    myRect.displayRectangleInfo();

    return 0;
}

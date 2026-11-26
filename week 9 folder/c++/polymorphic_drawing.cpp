// ACTIVITY 4: POLYMORPHIC DRAWING PROGRAM
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Rectangle" << endl;
    }
};

class Triangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Triangle" << endl;
    }
};

void renderCanvas(const Shape* shape) {
    shape->draw();
}

int main() {
    vector<unique_ptr<Shape>> canvas;

    canvas.push_back(make_unique<Circle>());
    canvas.push_back(make_unique<Rectangle>());
    canvas.push_back(make_unique<Triangle>());
    canvas.push_back(make_unique<Circle>());

    cout << "--- Rendering Canvas ---" << endl;
    for (const auto& shape : canvas) {
        renderCanvas(shape.get());
    }

    // unique_ptr automatically cleans up the allocated objects.
    return 0;
}

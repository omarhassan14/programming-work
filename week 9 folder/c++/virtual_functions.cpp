// ACTIVITY 2: VIRTUAL FUNCTIONS
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal makes a generic sound." << endl;
    }

    // Virtual destructor makes deletion through Animal* safe.
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};

int main() {
    cout << "--- With Virtual Keyword ---" << endl;

    Animal* myPet = new Dog();
    myPet->speak();

    delete myPet;
    return 0;
}

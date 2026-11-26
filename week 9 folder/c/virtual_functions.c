// ACTIVITY 2: SIMULATING VIRTUAL FUNCTIONS IN C
#include <stdio.h>

typedef void (*SpeakFunction)(void);

struct Animal {
    SpeakFunction speak;
};

struct Dog {
    struct Animal base;
};

void genericSound(void) {
    printf("Animal makes a generic sound.\n");
}

void dogBark(void) {
    printf("Dog barks: Woof! Woof!\n");
}

int main(void) {
    printf("--- Simulating Non-Virtual (Base only) ---\n");
    struct Animal myAnimal;
    myAnimal.speak = genericSound;
    myAnimal.speak();

    printf("\n--- Simulating Virtual (Dynamic binding) ---\n");
    struct Dog myDog;
    myDog.base.speak = dogBark;

    struct Animal *pet = (struct Animal *)&myDog;
    pet->speak();

    return 0;
}

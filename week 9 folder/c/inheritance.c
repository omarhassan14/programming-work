// ACTIVITY 1: SIMULATING INHERITANCE IN C
#include <stdio.h>
#include <string.h>

struct Shape {
    char color[20];
};

struct Circle {
    struct Shape base;  // Base struct is the first member
    double radius;
};

int main(void) {
    struct Circle myCircle;

    strcpy(myCircle.base.color, "Red");
    myCircle.radius = 5.0;

    printf("Circle Color (Inherited): %s\n", myCircle.base.color);
    printf("Circle Radius (Specific): %.2f\n", myCircle.radius);

    return 0;
}

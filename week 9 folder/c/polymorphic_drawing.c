// ACTIVITY 4: POLYMORPHIC DRAWING PROGRAM IN C
#include <stdio.h>

struct Shape {
    void (*draw)(void);
};

struct Circle {
    struct Shape base;
};

struct Rectangle {
    struct Shape base;
};

struct Triangle {
    struct Shape base;
};

void drawCircle(void) {
    printf("Drawing a Circle\n");
}

void drawRectangle(void) {
    printf("Drawing a Rectangle\n");
}

void drawTriangle(void) {
    printf("Drawing a Triangle\n");
}

void renderCanvas(struct Shape *shapePtr) {
    if (shapePtr != NULL && shapePtr->draw != NULL) {
        shapePtr->draw();
    }
}

int main(void) {
    struct Circle c1;
    struct Rectangle r1;
    struct Triangle t1;
    struct Circle c2;

    c1.base.draw = drawCircle;
    r1.base.draw = drawRectangle;
    t1.base.draw = drawTriangle;
    c2.base.draw = drawCircle;

    struct Shape *canvas[4];
    canvas[0] = (struct Shape *)&c1;
    canvas[1] = (struct Shape *)&r1;
    canvas[2] = (struct Shape *)&t1;
    canvas[3] = (struct Shape *)&c2;

    printf("--- Rendering Canvas ---\n");
    for (int i = 0; i < 4; i++) {
        renderCanvas(canvas[i]);
    }

    return 0;
}

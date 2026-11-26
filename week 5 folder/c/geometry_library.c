// WEEK 5 - ACTIVITY 4: GEOMETRY FUNCTION LIBRARY
#include <stdio.h>

#define PI 3.14159

double areaOfCircle(double radius) {
    if (radius < 0) return -1.0;
    return PI * radius * radius;
}

double areaOfRectangle(double length, double width) {
    if (length < 0 || width < 0) return -1.0;
    return length * width;
}

double areaOfTriangle(double base, double height) {
    if (base < 0 || height < 0) return -1.0;
    return 0.5 * base * height;
}

double areaOfSquare(double side) {
    if (side < 0) return -1.0;
    return side * side;
}

double perimeterOfRectangle(double length, double width) {
    if (length < 0 || width < 0) return -1.0;
    return 2 * (length + width);
}

void displayMenu(void) {
    printf("\\n===== GEOMETRY CALCULATOR =====\n");
    printf("1. Area of Circle\n");
    printf("2. Area of Rectangle\n");
    printf("3. Area of Triangle\n");
    printf("4. Area of Square (challenge)\n");
    printf("5. Perimeter of Rectangle (challenge)\n");
    printf("6. Calculate all areas\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main(void) {
    int choice;
    double radius, length, width, base, height, side;

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a menu number.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter radius: ");
                if (scanf("%lf", &radius) != 1 || radius < 0) {
                    printf("Invalid radius. Use a non-negative number.\n");
                    return 1;
                }
                printf("Area of circle: %.2f\n", areaOfCircle(radius));
                break;
            case 2:
                printf("Enter length and width: ");
                if (scanf("%lf %lf", &length, &width) != 2 || length < 0 || width < 0) {
                    printf("Invalid dimensions. Use non-negative numbers.\n");
                    return 1;
                }
                printf("Area of rectangle: %.2f\n", areaOfRectangle(length, width));
                printf("Perimeter of rectangle: %.2f\n", perimeterOfRectangle(length, width));
                break;
            case 3:
                printf("Enter base and height: ");
                if (scanf("%lf %lf", &base, &height) != 2 || base < 0 || height < 0) {
                    printf("Invalid dimensions. Use non-negative numbers.\n");
                    return 1;
                }
                printf("Area of triangle: %.2f\n", areaOfTriangle(base, height));
                break;
            case 4:
                printf("Enter side: ");
                if (scanf("%lf", &side) != 1 || side < 0) {
                    printf("Invalid side. Use a non-negative number.\n");
                    return 1;
                }
                printf("Area of square: %.2f\n", areaOfSquare(side));
                break;
            case 5:
                printf("Enter length and width: ");
                if (scanf("%lf %lf", &length, &width) != 2 || length < 0 || width < 0) {
                    printf("Invalid dimensions. Use non-negative numbers.\n");
                    return 1;
                }
                printf("Perimeter of rectangle: %.2f\n", perimeterOfRectangle(length, width));
                break;
            case 6:
                printf("Enter radius: ");
                if (scanf("%lf", &radius) != 1 || radius < 0) return 1;
                printf("Enter rectangle length and width: ");
                if (scanf("%lf %lf", &length, &width) != 2 || length < 0 || width < 0) return 1;
                printf("Enter triangle base and height: ");
                if (scanf("%lf %lf", &base, &height) != 2 || base < 0 || height < 0) return 1;
                printf("Circle area: %.2f\n", areaOfCircle(radius));
                printf("Rectangle area: %.2f\n", areaOfRectangle(length, width));
                printf("Triangle area: %.2f\n", areaOfTriangle(base, height));
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose 1 to 7.\n");
        }
    } while (choice != 7);

    return 0;
}

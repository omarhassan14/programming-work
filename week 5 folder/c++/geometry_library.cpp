// WEEK 5 - ACTIVITY 4: GEOMETRY FUNCTION LIBRARY
#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.14159;

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

void displayMenu() {
    cout << "\\n===== GEOMETRY CALCULATOR =====" << endl;
    cout << "1. Area of Circle" << endl;
    cout << "2. Area of Rectangle" << endl;
    cout << "3. Area of Triangle" << endl;
    cout << "4. Area of Square (challenge)" << endl;
    cout << "5. Perimeter of Rectangle (challenge)" << endl;
    cout << "6. Calculate all areas" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    double radius, length, width, base, height, side;

    do {
        displayMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a menu number." << endl;
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Enter radius: ";
                if (!(cin >> radius) || radius < 0) {
                    cout << "Invalid radius. Use a non-negative number." << endl;
                    return 1;
                }
                cout << "Area of circle: " << fixed << setprecision(2)
                     << areaOfCircle(radius) << endl;
                break;
            case 2:
                cout << "Enter length and width: ";
                if (!(cin >> length >> width) || length < 0 || width < 0) {
                    cout << "Invalid dimensions. Use non-negative numbers." << endl;
                    return 1;
                }
                cout << "Area of rectangle: " << fixed << setprecision(2)
                     << areaOfRectangle(length, width) << endl;
                cout << "Perimeter of rectangle: "
                     << perimeterOfRectangle(length, width) << endl;
                break;
            case 3:
                cout << "Enter base and height: ";
                if (!(cin >> base >> height) || base < 0 || height < 0) {
                    cout << "Invalid dimensions. Use non-negative numbers." << endl;
                    return 1;
                }
                cout << "Area of triangle: " << fixed << setprecision(2)
                     << areaOfTriangle(base, height) << endl;
                break;
            case 4:
                cout << "Enter side: ";
                if (!(cin >> side) || side < 0) {
                    cout << "Invalid side. Use a non-negative number." << endl;
                    return 1;
                }
                cout << "Area of square: " << fixed << setprecision(2)
                     << areaOfSquare(side) << endl;
                break;
            case 5:
                cout << "Enter length and width: ";
                if (!(cin >> length >> width) || length < 0 || width < 0) {
                    cout << "Invalid dimensions. Use non-negative numbers." << endl;
                    return 1;
                }
                cout << "Perimeter of rectangle: " << fixed << setprecision(2)
                     << perimeterOfRectangle(length, width) << endl;
                break;
            case 6:
                cout << "Enter radius: ";
                if (!(cin >> radius) || radius < 0) return 1;
                cout << "Enter rectangle length and width: ";
                if (!(cin >> length >> width) || length < 0 || width < 0) return 1;
                cout << "Enter triangle base and height: ";
                if (!(cin >> base >> height) || base < 0 || height < 0) return 1;
                cout << "Circle area: " << fixed << setprecision(2) << areaOfCircle(radius) << endl;
                cout << "Rectangle area: " << areaOfRectangle(length, width) << endl;
                cout << "Triangle area: " << areaOfTriangle(base, height) << endl;
                break;
            case 7:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please choose 1 to 7." << endl;
        }
    } while (choice != 7);

    return 0;
}

// ============================================================
// WEEK 6 - ACTIVITY 2: 2D ARRAY MEMORY LAYOUT (ROW-MAJOR) (C++)
// ============================================================
#include <iostream>
using namespace std;

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "Row-major traversal (row by row):" << endl;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    cout << "\nMemory addresses (address spacing depends on sizeof(int)):" << endl;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << "matrix[" << row << "][" << col << "] = "
                 << matrix[row][col] << " at address "
                 << static_cast<const void *>(&matrix[row][col]) << endl;
        }
    }

    cout << "\nColumn-major traversal (column by column):" << endl;
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 3; row++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    cout << "\nObservation: C++ stores 2D arrays in row-major order." << endl;
    cout << "Row 0 is stored completely, then row 1, then row 2." << endl;
    return 0;
}

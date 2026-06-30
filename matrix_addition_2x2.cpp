#include <iostream>

using namespace std;

int main() {
    // Declare 2D arrays to represent a 2x2 matrices
    int matrixA[2][2];
    int matrixB[2][2];
    int resultMatrix[2][2];

    cout << "--- 2x2 Matrix Addition Calculator ---\n\n";

    // 1. Collects data for Matrix A
    cout << "Enter the 4 elements of Matrix A (row by row):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }

    // 2. Collects data for Matrix B
    cout << "\nEnter the 4 elements of Matrix B (row by row):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }

    // 3. Mathematical computation: C_ij = A_ij + B_ij
    //  nested loops are used to go through the rows (i) and columns (j):
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // 4. Displays the resulting matrix in a readable grid format
    cout << "\nResulting Matrix (A + B):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << resultMatrix[i][j] << " ";
        }
        cout << "\n"; //skips over to a new line
    }

    return 0;
}

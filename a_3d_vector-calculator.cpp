#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Basic 1D arrays for 3D coordinates (x, y, z)
    
    double vecA[3];
    double vecB[3];
    int choice;

    cout << "============================\n";
    cout << "   3D VECTOR MATHS ENGINE       \n";
    cout << "=============================\n\n";

    // A validation and operational loop
    do {
        cout << "-- Main menu --\n";
        cout << "1. Calculate Vector Magnitude (Length)\n";
        cout << "2. Calculate Dot Product (Scalar)\n";
        cout << "3. Exit\n";
        cout << "Select operation: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Magnitude Calculation..:
                cout << "\nEnter 3D Vector coordinates (x y z) separated by spaces: ";
                cin >> vecA[0] >> vecA[1] >> vecA[2];
                
                // Using pure cmath functions..: sqrt(x^2 + y^2 + z^2)
                double magnitude = sqrt(pow(vecA[0], 2) + pow(vecA[1], 2) + pow(vecA[2], 2));
                
                cout << fixed << setprecision(2);
                cout << "  -> [RESULT] Vector Magnitude: " << magnitude << "\n\n";
                break;
            }
            case 2: {
                // Dot Product Calculation...:
                cout << "\nEnter first 3D Vector (x y z): ";
                cin >> vecA[0] >> vecA[1] >> vecA[2];
                cout << "Enter second 3D Vector (x y z): ";
                cin >> vecB[0] >> vecB[1] >> vecB[2];
                
                // (x1*x2) + (y1*y2) + (z1*z2)
                double dotProduct = (vecA[0] * vecB[0]) + (vecA[1] * vecB[1]) + (vecA[2] * vecB[2]);
                
                cout << fixed << setprecision(2);
                cout << "  -> [RESULT] Dot Product: " << dotProduct << "\n\n";
                break;
            }
            case 3:
                cout << "Terminating Vector Engine. Goodbye ;).\n";
                break;
            default:
                cout << "[ERROR] Invalid choice. Please select 1, 2, or 3.\n\n";
        }
    } while (choice != 3);

    return 0;
}

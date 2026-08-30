#include <iostream>

using namespace std;

// Cramer's Rule:
// For the systems:a1*x + b1*y = c1
                   a2*x + b2*y = c2
int main() {
    double a1, b1, c1;
    double a2, b2, c2;

    cout << "=====================================\n";
    cout << "  2x2 LINEAR EQUATION SYSTEM SOLVER    \n";
    cout << "=====================================\n";

    cout << "Enter Equation 1 coefficients (a1 b1 c1 for a1*x + b1*y = c1):\n";
    cin >> a1 >> b1 >> c1;

    cout << "Enter Equation 2 coefficients (a2 b2 c2 for a2*x + b2*y = c2):\n";
    cin >> a2 >> b2 >> c2;

    // Main determinant: D = a1*b2 - a2*b1
    double D = (a1 * b2) - (a2 * b1);

    // Dx determinant: replace x-column with constants c1, c2
    double Dx = (c1 * b2) - (c2 * b1);

    // Dy determinant: replace y-column with constants c1, c2
    double Dy = (a1 * c2) - (a2 * c1);

    if (D == 0) {
        if (Dx == 0 && Dy == 0) {
            cout << "The system has infinitely many solutions (dependent system).\n";
        } else {
            cout << "The system has no unique solution (inconsistent system).\n";
        }
    } else {
        double x = Dx / D;
        double y = Dy / D;

        cout << "Determinant (D)  : " << D << "\n";
        cout << "Solution (x)     : " << x << "\n";
        cout << "Solution (y)     : " << y << "\n";
    }
    cout << "-Thanks for choosing this calculator!Come again!-\n";

    return 0;
}

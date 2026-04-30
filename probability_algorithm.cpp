#include <iostream>
using namespace std;

// The Factorial Engine
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
     return 1;}
    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Algorithm for Permutations (nPr)
unsigned long long permutation(int n, int r) {
    if (r > n) return 0;
    return factorial(n) / factorial(n - r);
}

// Algorithm for Combinations (nCr)
unsigned long long combination(int n, int r) {
    if (r > n) return 0;
    return factorial(n) / (factorial(n - r) * factorial(r));
}

int main() {
    int choice, n, r;
//the logic to help compute the parameters
    while (true) {
        cout << " Combinatorics & Probability Algorithm";
        cout << "1) Calculate Factorial (n!)\n";
        cout << "2) Calculate Permutation (nPr)\n";
        cout << "3) Calculate Combination (nCr)\n";
        cout << "0) Exit\n";
        cout << "Enter protocol: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Shutting down engine...\n";
            break;
        }
//to help deal with multiple scenarios
        switch (choice) {
            case 1:
                cout << "Enter n: "; cin >> n;
                cout << ">>> " << n << "! = " << factorial(n) << " <<<\n";
                break;
            case 2:
                cout << "Enter n (total items): "; cin >> n;
                cout << "Enter r (items to arrange): "; cin >> r;
                cout << ">>> " << n << "P" << r << " = " << permutation(n, r) << " <<<\n";
                break;
            case 3:
                cout << "Enter n (total items): "; cin >> n;
                cout << "Enter r (items to choose): "; cin >> r;
                cout << ">>> " << n << "C" << r << " = " << combination(n, r) << " <<<\n";
                break;
            default:
                cout << "Invalid protocol! Pick 1, 2, 3, or 0.\n";
                continue;
        }
    }

    return 0;
}

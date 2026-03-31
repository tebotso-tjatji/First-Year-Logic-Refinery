#include <iostream>
using namespace std;

// Algorithm for calculating the Area of Rectangle
double get_rectangle() {
    double w, h;
    cout << "Enter Width: "; cin >> w;
    cout << "Enter Height: "; cin >> h;
    return w * h;
}

// Algorithm for calculating the Area of Triangle
double get_triangle() {
    double b, h;
    cout << "Enter Base: "; cin >> b;
    cout << "Enter Height: "; cin >> h;
    return 0.5 * b * h;
}

// Algorithm for calculating the Area of Circle
double get_circle() {
    double r;
    const double PI = 3.14159;
    cout << "Enter Radius: "; cin >> r;
    return PI * r * r;
}

// Algorithm for calculating the Area of Square
double get_square() {
    double s;
    cout << "Enter Side Length: "; cin >> s;
    return s * s;
}

// Main Function.
int main() {
    int choice;
    double area;

    while (true) {
        cout << "\n--- Area Calculator ---\n";
        cout << "1) Rectangle\n2) Triangle\n3) Circle\n4) Square\n0) Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
      
        // to escape the program's infinite loop.
        if (choice == 0) {
            cout << "Shutting down...\n";
            break; 
        }
      
        //handling scenarios where the user ignores instructions:
        switch (choice) {
            case 1: 
                area = get_rectangle(); 
                break;
            case 2: 
                area = get_triangle(); 
                break;
            case 3:
                area = get_circle();
                break;
            case 4:
                area = get_square();
                break;
            default: 
                cout << "Invalid choice! Pick 1, 2, 3, 4, or 0.\n";
                continue; 
        }
        cout << ">>> The Area is: " << area << " <<<\n";
    }

    return 0;
}

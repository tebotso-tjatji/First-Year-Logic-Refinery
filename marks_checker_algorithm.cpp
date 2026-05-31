#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // max array size
    const int MAX_STUDENTS = 100;
    double marks[MAX_STUDENTS];
    
    int totalStudents;
    double sum = 0.0;
    int passCount = 0;

    cout << "==================================================\n";
    cout << "     STUDENT MARKS VALIDATION & ANALYTICS          \n";
    cout << "==================================================\n\n";

    cout << "Enter the total number of students (Max 100): ";
    cin >> totalStudents;

    // Basic validation for array limits
    if (totalStudents <= 0 || totalStudents > MAX_STUDENTS) {
        cout << "[ERROR] Invalid number of students. Exiting.\n";
        return 1;
    }

    // Manual input and validation loop
    for (int i = 0; i < totalStudents; i++) {
        double inputMark;
        cout << "Enter final mark for Student " << (i + 1) << " (0 - 100): ";
        cin >> inputMark;

        // Basic logical check
        if (inputMark >= 0.0 && inputMark <= 100.0) {
            marks[i] = inputMark;
            sum += inputMark; // sum accumulator
            
            if (inputMark >= 50.0) {
                passCount++; // increments on each passing count
            }
        } else {
            cout << "  [INVALID] Mark must be between 0 and 100. Try again.\n";
            i--; // Decrements the counter to force the user to redo this student
        }
    }

    int choice;
    do {
        cout << "\n--- Analytics Engine Menu ---\n";
        cout << "1. Display Class Statistics\n";
        cout << "2. Exit Dashboard\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Manual mathematical calculations
                double mean = sum / totalStudents;
                double passRate = ((double)passCount / totalStudents) * 100.0;

                cout << fixed << setprecision(2);
                cout << "\n====================================\n";
                cout << "         STATISTICAL REPORT         \n";
                cout << "====================================\n";
                cout << " Total Records Processed : " << totalStudents << "\n";
                cout << " Class Average (Mean)    : " << mean << "%\n";
                cout << " Total Passes (>= 50%)   : " << passCount << "\n";
                cout << " Total Failures          : " << (totalStudents - passCount) << "\n";
                cout << " Class Pass Rate         : " << passRate << "%\n";
                cout << "====================================\n";
                break;
            }
            case 2:
                cout << "Exiting system. Goodbye.\n";
                break;
            default:
                cout << "[ERROR!] Invalid menu choice. Please select 1 or 2.\n";
        }
    } while (choice != 2);

    return 0;
}

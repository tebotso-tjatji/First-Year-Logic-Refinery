#include <iostream>
using namespace std;

int main() {
    // I used a standard 5-digit odometer for simplicity
    int max_reading = 99999; 
    int previous, current, distance;

    cout << "--- Simple Odometer Simulator ---\n";
    
    // 1.Inputs
    cout << "Enter previous reading: ";
    cin >> previous;
    
    cout << "Enter current reading: ";
    cin >> current;

    // 2. The Logic circuit...
    if (current >= previous) {
        distance = current - previous;
    } else {
        // Distance to the max, plus 1 to roll over to 0, plus the new reading
        distance = (max_reading - previous + 1) + current;
    }

    // 3. Output
    cout << "Distance traveled: " << distance << endl;

    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
//the algorithm's title:
    cout << "       PEDOMETER & KINEMATICS ENGINE      \n";

    int steps;
    double strideLength; // in meters
    double weight;       // in kilograms

  //average calorie burned for each step.
    const double CALORIES_PER_STEP = 0.04; 
    
    cout << "Enter total steps recorded by sensor: ";
    cin >> steps;
    
    if (steps < 0) {
        cout << "[Error] Step count cannot be negative.\n";
        return 1;
    }

    cout << "Enter average stride length in meters : ";
    cin >> strideLength;

    cout << "Enter body weight in kg (for energy calculation): ";
    cin >> weight;

    // 1. Distance Calculation (The displacement shift)
    // Distance in kilometers = (steps * stride length) / 1000
    double distanceKm = (steps * strideLength) / 1000;

    // 2. Caloric Burn Calculation
    // Adjusted by weight: heavier mass requires more kinetic energy to move
    double weightFactor = weight / 70; // Normalized against an average 70kg person
    double caloriesBurned = steps * CALORIES_PER_STEP * weightFactor;

    cout << fixed << setprecision(2);
    cout << "Total Steps        : " << steps << "\n";
    cout << "Distance Travelled : " << distanceKm << " km\n";
    cout << "Calories Burned    : " << caloriesBurned << " kcal\n";
//send off:
    cout << "-Thanks for choosing this calculator!Do come back again!-\n";

    return 0;
}

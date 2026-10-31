#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// Standard non-leap year month lengths
const int DAYS_IN_MONTH[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Holiday {
    int month;
    int day;
    string name;
    string honorific;
};

// Convert a Month/Day into a 1-365 Day of Year integer
int getDayOfYear(int month, int day) {
    int doy = 0;
    for (int i = 1; i < month; ++i) {
        doy += DAYS_IN_MONTH[i];
    }
    doy += day;
    return doy;
}

// Calculate shortest distance between two days on a 365-day loop
int getCircularDistance(int doy1, int doy2) {
    int diff = abs(doy1 - doy2);
    return min(diff, 365 - diff);
}

// Validation check for user input
bool isValidDate(int month, int day) {
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > DAYS_IN_MONTH[month]) return false;
    return true;
}

int main() {
    // Database of fixed SA Holidays + Halloween(i dont understand why we cant have it in SA,so i'm adding it)
    vector<Holiday> holidays = {
        {1, 1, "New Year's Day", "A fresh start. Time to deploy the new year's commits."},
        {3, 21, "Human Rights Day", "Honor the past. A day of national reflection."},
        {4, 27, "Freedom Day", "Commemorating the first democratic elections in SA."},
        {5, 1, "Workers' Day", "Take a break from compiling. You've earned the rest."},
        {6, 16, "Youth Day", "Honoring the youth of '76. The future is built today."},
        {8, 9, "National Women's Day", "Tribute to the pioneers who marched for justice."},
        {9, 24, "Heritage Day", "Fire up the braai. Celebrate the rainbow nation."},
        {10, 31, "Halloween", "Spooky season protocol active. Beware of ghost bugs in your code."},
        {12, 16, "Day of Reconciliation", "Bridging divides and repairing the system."},
        {12, 25, "Christmas Day", "System offline. Mandatory festive downtime."},
        {12, 26, "Day of Goodwill", "Boxing day. Handle leftover festive tasks."}
    };

    int inputMonth, inputDay;

    cout << " SA HOLIDAY & PROXIMITY TRACKER...\n";
    cout << "========================================\n";
    cout << "Enter current month (1-12): ";
    cin >> inputMonth;
    cout << "Enter current day (1-31): ";
    cin >> inputDay;

    if (!isValidDate(inputMonth, inputDay)) {
        cout << "\n[Error] Invalid date detected. Terminating process.\n";
        return 1;
    }

    int targetDoy = getDayOfYear(inputMonth, inputDay);
    
    bool exactMatch = false;
    int minDistance = 366;
    Holiday nearestHoliday;

    // Nearest-Neighbor Search
    for (const auto& h : holidays) {
        int holidayDoy = getDayOfYear(h.month, h.day);
        
        if (targetDoy == holidayDoy) {
            cout << "\n[STATUS] Public Holiday Confirmed!" << endl;
            cout << "Holiday: " << h.name << endl;
            cout << "Message: " << h.honorific << endl;
            exactMatch = true;
            break;
        }

        int dist = getCircularDistance(targetDoy, holidayDoy);
        if (dist < minDistance) {
            minDistance = dist;
            nearestHoliday = h;
        }
    }

    if (!exactMatch) {
        cout << "\n[STATUS] Standard Working Day." << endl;
        cout << "Keep grinding. The nearest holiday is " << nearestHoliday.name 
             << " (" << nearestHoliday.month << "/" << nearestHoliday.day << ")." << endl;
        cout << "Distance: Just " << minDistance << " days away." << endl;
    }

    return 0;
}

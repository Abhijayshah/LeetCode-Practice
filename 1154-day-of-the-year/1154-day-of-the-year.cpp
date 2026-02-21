class Solution {
public:
    int dayOfYear(string date) {
        
        // Extract year, month, day from string
        int year  = stoi(date.substr(0, 4));   // First 4 characters = year
        int month = stoi(date.substr(5, 2));   // Characters 5-6 = month
        int day   = stoi(date.substr(8, 2));   // Characters 8-9 = day
        
        // Days in each month (non-leap year)
        vector<int> daysInMonth = 
            {31, 28, 31, 30, 31, 30, 
             31, 31, 30, 31, 30, 31};
        
        // Check if leap year
        bool isLeap = false;
        
        if ((year % 4 == 0 && year % 100 != 0) || 
            (year % 400 == 0)) {
            isLeap = true; // It's a leap year
        }
        
        int totalDays = 0; // Store cumulative days
        
        // Add days of previous months
        for (int i = 0; i < month - 1; i++) {
            totalDays += daysInMonth[i];
        }
        
        // If leap year and month after February, add 1 extra day
        if (isLeap && month > 2) {
            totalDays += 1;
        }
        
        totalDays += day; // Add current month's days
        
        return totalDays; // Return final day of year
    }
};
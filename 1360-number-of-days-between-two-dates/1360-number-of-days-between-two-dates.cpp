class Solution {
public:
    
    // Function to check if a year is leap
    bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    
    // Convert a date into total days since 1971-01-01
    int convertToDays(string date) {
        
        int year  = stoi(date.substr(0, 4));  // Extract year
        int month = stoi(date.substr(5, 2));  // Extract month
        int day   = stoi(date.substr(8, 2));  // Extract day
        
        vector<int> daysInMonth = 
        {31,28,31,30,31,30,31,31,30,31,30,31};
        
        int totalDays = 0; // Store total days
        
        // Add days for all previous years
        for (int y = 1971; y < year; y++) {
            totalDays += isLeap(y) ? 366 : 365;
        }
        
        // Add days for previous months of current year
        for (int m = 1; m < month; m++) {
            totalDays += daysInMonth[m - 1];
            
            // Add one extra day if February in leap year
            if (m == 2 && isLeap(year)) {
                totalDays += 1;
            }
        }
        
        totalDays += day; // Add days of current month
        
        return totalDays; // Return total days
    }
    
    int daysBetweenDates(string date1, string date2) {
        
        int days1 = convertToDays(date1); // Convert first date
        int days2 = convertToDays(date2); // Convert second date
        
        return abs(days1 - days2); // Return absolute difference
    }
};
class Solution {
public:
    bool checkRecord(string s) {

        int absentCount = 0;
        int lateStreak = 0;

        for (char c : s) {
            if (c == 'A') {
                absentCount++;
                lateStreak = 0;   // reset late streak
            } 
            else if (c == 'L') {
                lateStreak++;
            } 
            else { // 'P'
                lateStreak = 0;
            }

            // Check conditions
            if (absentCount >= 2 || lateStreak >= 3)
                return false;
        }

        return true;
    }
};

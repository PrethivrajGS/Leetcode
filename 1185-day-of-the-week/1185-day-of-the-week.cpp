class Solution {
public:
    bool isLeap(int year) {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = {
            "Sunday","Monday","Tuesday",
            "Wednesday","Thursday","Friday","Saturday"
        };

        vector<int> monthDays = {
            31,28,31,30,31,30,
            31,31,30,31,30,31
        };

        int totalDays = 0;
        for (int y = 1971; y < year; y++) {
            totalDays += isLeap(y) ? 366 : 365;
        }
        for (int m = 1; m < month; m++) {
            if (m == 2 && isLeap(year))
                totalDays += 29;
            else
                totalDays += monthDays[m - 1];
        }
        totalDays += day;
        return days[(totalDays + 4) % 7];
    }
};
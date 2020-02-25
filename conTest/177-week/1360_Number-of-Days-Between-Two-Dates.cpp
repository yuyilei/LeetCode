/*
Write a program to count the number of days between two dates.

The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.

 

Example 1:

Input: date1 = "2019-06-29", date2 = "2019-06-30"
Output: 1
Example 2:

Input: date1 = "2020-01-15", date2 = "2019-12-31"
Output: 15
 

Constraints:

The given dates are valid dates between the years 1971 and 2100.

*/


class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int res = daysFromStart(date1) - daysFromStart(date2);
        return abs(res);
    }
private:
    // 计算date距离1971-01-01的天数
    int daysFromStart(string date) {
        int eachDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        int dy = year - 1971;
        //  2000 是闰年，所以不用单独判断
        // LeapNum 是year到1971之间有几个闰年（year年不算）
        int leapNum = (year-1969)/4;
        // 多一个闰年就多加一天
        int yearSum = dy*365 + leapNum;
        int monthSum = 0;
        for (int i = 0; i < month-1; i++) {
            monthSum += eachDay[i];
        }
        // 月份大于等于3，且此年是闰年，需要多加一天
        if (month >= 3 && isLeapYear(year)) {
            monthSum += 1;
        }
        return yearSum + monthSum + day;
    }
    bool isLeapYear(int year) {
        if (year % 100 != 0) {
            if (year % 4 == 0)
                return true;
            else
                return false;
        }
        else {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
    }
};

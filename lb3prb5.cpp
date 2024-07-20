// /*Program to convert time (hour, minute and second) in 12-hr format to
// 24-hr format.
// */
#include <iostream>
#include <cstring>
using namespace std;

class Time12 {
    int hour;
    int minute;
    int second;
    char period[3];

public:
    Time12()  {
          hour = 0;
        minute = 0;
        second = 0;
        strcpy(period, "AM");
    }

    Time12(int h, int m, int s, char* p){
        hour = h;
        minute = m;
        second = s;
        strcpy(period, p);
    }

    int getHour()  {
        return hour;
    }

    int getMinute()  {
        return minute;
    }

    int getSecond()  {
        return second;
    }

     char* getPeriod()  {
        return period;
    }

    void settime() {
        cout << "Enter hour in 12-hour format: ";
        cin >> hour;
        cout << "Enter minutes: ";
        cin >> minute;
        cout << "Enter seconds: ";
        cin >> second;
        cout << "Enter period (AM/PM): ";
        cin >> period;
    }

    void displaytime()  {
        cout << "The time in 12-hour format is " << hour << ":" << minute << ":" << second << " " << period << endl;
    }
};

class Time24 {
    int hour;
    int minute;
    int second;

public:
    Time24() {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time24(int h, int m, int s)  {
        hour = h;
        minute = m;
        second = s;
    }

    Time24( Time12& time12) {
        hour = time12.getHour();
        minute = time12.getMinute();
        second = time12.getSecond();
        if (strcmp(time12.getPeriod(), "PM") == 0 && hour != 12) {
            hour += 12;
        } else if (strcmp(time12.getPeriod(), "AM") == 0 && hour == 12) {
            hour = 0;
        }
    }

    void display()  {
        cout << "24-hour format: " << hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    Time12 t1;
    t1.settime();
    t1.displaytime();

    Time24 t2 = t1; // Using type conversion
    t2.display();

    return 0;
}

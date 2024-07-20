/*Program to convert time (hour, minute and second) in 24-hr format to
 12-hr format.*/

#include <iostream>
#include <cstring>
using namespace std;

class Time24
{
    int hour;
    int minute;
    int second;

public:
    Time24()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time24(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    int getHour()
    {
        return hour;
    }

    int getMinute()
    {
        return minute;
    }

    int getSecond()
    {
        return second;
    }

    void settime()
    {
        cout << "Enter hour in 24 hour format: ";
        cin >> hour;
        cout << "Enter minutes: ";
        cin >> minute;
        cout << "Enter seconds: ";
        cin >> second;
    }

    void displaytime()
    {
        cout << "The time in 24 hour format is " << hour << "::" << minute << "::" << second << endl;
    }
};

class Time12
{
    int hour;
    int minute;
    int second;
    char period[3]; // For storing "AM" or "PM"

public:
    Time12()
    {
        hour = 0;
        minute = 0;
        second = 0;
        strcpy(period, "AM");
    }

    Time12(int h, int m, int s,  char *p) 
    {
         hour = h;
        minute = m;
        second = s;
        strcpy(period, p);
    }

    void display()
    {
        cout << "12-hour format: " << hour << ":" << minute << ":" << second << " " << period << endl;
    }

    // Conversion constructor from Time24 to Time12
    Time12(Time24 &time24)
    {
        hour = time24.getHour();
        minute = time24.getMinute();
        second = time24.getSecond();

        if (hour == 0)
        {
            hour = 12;
            strcpy(period, "AM");
        }
        else if (hour == 12)
        {
            strcpy(period, "PM");
        }
        else if (hour > 12)
        {
            hour -= 12;
            strcpy(period, "PM");
        }
        else
        {
            strcpy(period, "AM");
        }
    }
};

int main()
{
    Time24 t1;
    t1.settime();
    t1.displaytime();

    Time12 t2 = t1; // Using type conversion
    t2.display();

    return 0;
}

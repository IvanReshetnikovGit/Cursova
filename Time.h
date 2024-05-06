#pragma once
#include <iostream>
#include "check_number.h"
using namespace std;

class Time
{
    int hour;
    int minute;
    int second;
    
public:
    Time(int hour, int minute, int second);
    Time();
    Time(const Time &time);
    Time(Time &&time);

    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    virtual string getTime();

    void operator+=(const Time& t);
    void operator-=(const Time& t);
    Time &operator=(const Time& t);
    bool operator ==(const Time& t);

    friend ostream& operator<<(ostream& os, const Time& t);
    friend istream& operator>>(istream& in, Time& t);

    bool operator <(const Time& t);
};
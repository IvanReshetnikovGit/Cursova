#include "Time.h"

Time::Time(int hour, int minute, int second)
{
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

Time::Time(){ }

Time::Time(const Time &time) 
{
    hour = time.hour;
    minute = time.minute;
    second = time.second;
}

Time::Time(Time &&time)
{
    hour = time.hour;
    minute = time.minute;
    second = time.second;

    time.hour = 0;
    time.minute = 0;
    time.second = 0;
}

void Time::setHour(int hour)
{
    if (hour >= 0 && hour <= 23)
        this->hour = hour;
    else
        throw invalid_argument("hour not entered correct");
}

void Time::setMinute(int minute)
{
    if (minute >= 0 && minute <= 59)
        this->minute = minute;
    else
        throw invalid_argument("minute not entered correct");
}

void Time::setSecond(int second)
{
 
    if (second >= 0 && second <= 59)
        this->second = second;
    else
        throw invalid_argument("second not entered correct");
}

int Time::getHour() const
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}

int Time::getSecond() const
{
    return second;
}

void Time::operator+=(const Time& t)
{
    hour += t.hour;
    minute += t.minute;
    second += t.second;
}

void Time::operator-=(const Time& t)
{
    hour -= t.hour;
    minute -= t.minute;
    second -= t.second;
}

ostream& operator<<(ostream& os, const Time& t)
{
    os << t.hour << ":" << t.minute << ":" << t.second;
    return os;
}

istream& operator>>(istream& in, Time& t) 
{
    string TestHour,TestMinute,TestSecond;
    int hour, minute, second;
    in >> TestHour >> TestMinute >> TestSecond;
    
    hour = check_number(TestHour);
    minute = check_number(TestMinute);
    second = check_number(TestSecond);

    t.setHour(hour);
    t.setMinute(minute);
    t.setSecond(second);
    return in;
}

Time& Time::operator=(const Time& t)
{
    hour = t.hour;
    minute = t.minute;
    second = t.second;
    return *this;
}

string Time::getTime()
{
    string t = to_string(hour) +":"+ to_string(minute) +":"+ to_string(second);
    return t;
}

bool Time::operator <(const Time& t)
{
    if (hour < t.hour)
        return true;
    else if (hour > t.hour)
        return false;
    else
    {
        if (minute < t.minute)
            return true;
        else if (minute > t.minute)
            return false;
        else 
            return second < t.second;
    }
}

bool Time::operator ==(const Time& t)
{
    return hour==t.hour && minute == t.minute && second == t.second;
}
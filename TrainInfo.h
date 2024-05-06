#pragma once
#include "Time.h"
class TrainInfo : public Time
{
    string Destination;
    Time DepartureTime;
    int Peron;

public:
    TrainInfo();
    TrainInfo(Time t,string Destination, int Peron);
    void setDestination(string Destination);
    void setDepartureTime(Time DepartureTime);
    void setPeron(int Peron);

    string getDestination();
    Time getDepartureTime();
    int getPeron();

    friend ostream& operator<<(ostream& os, TrainInfo& t);
    friend istream& operator>>(istream& is,const TrainInfo& t);
    string getTime() override;
    bool operator ==(const TrainInfo& other);
};
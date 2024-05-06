#include "TrainInfo.h"

TrainInfo::TrainInfo(){};

TrainInfo::TrainInfo(Time t,string Destination, int Peron)
{
    DepartureTime = t;
    this->Destination = Destination;
    this->Peron = Peron;
}

void TrainInfo::setDestination(string Destination)
{
    this->Destination = Destination;
}
void TrainInfo::setDepartureTime(Time DepartureTime)
{
    this->DepartureTime = DepartureTime;
}
void TrainInfo::setPeron(int Peron)
{
    if (Peron > 0)
        this->Peron = Peron;
    else
        throw invalid_argument("Peron entered incorrectly");
}

string TrainInfo::getDestination()
{
    return Destination;
}
Time TrainInfo::getDepartureTime()
{
    return DepartureTime;
}
int TrainInfo::getPeron()
{
    return Peron;
}

ostream& operator<<(ostream& os, TrainInfo& t)
{
    os << t.getDepartureTime() <<" "<< t.getDestination()<<" " << t.getPeron();
    return os;
}
istream& operator>>(istream& in, TrainInfo& t)
{
    int hour,minute,second;

    Time DepartureTime;
    int Peron;
    string Destination;

    in >> hour >> minute >> second >> Peron >> Destination;

    DepartureTime.setHour(hour);
    DepartureTime.setMinute(minute);
    DepartureTime.setSecond(second);
    
    t.setDepartureTime(DepartureTime);
    t.setPeron(Peron);
    t.setDestination(Destination);
    return in;
}

bool TrainInfo::operator ==(const TrainInfo& other )
{
    return DepartureTime == other.DepartureTime && Destination == other.Destination && Peron == other.Peron;
}

string TrainInfo::getTime()
{
    string t = to_string(DepartureTime.getHour()) +":"+ to_string(DepartureTime.getMinute()) +":"+ to_string(DepartureTime.getSecond());
    return t;
}
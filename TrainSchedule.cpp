#include "TrainSchedule.h"

void Trainschedule::closestTrain(string Destination) {
    TrainInfo min;
    int ind;

    for (vectorClass<TrainInfo>::iterator it = Schedule.begin(); it != Schedule.end(); ++it) {
        if ((*it).getDestination() == Destination) {
            min = *it;
            ind = it - Schedule.begin(); 
            break;
        }
    }
    if(!min.getDestination().empty() && ind != Schedule.getcapacity())
    {
        for (int i = ind+1; i < Schedule.getcapacity(); i++)
        {
            if(!(min.getDepartureTime()<Schedule.get(i).getDepartureTime()) && Schedule.get(i).getDestination() == Destination)
            {
                min = Schedule.get(i);
            }
        }
        cout<<"Closest train is: "<< min<<endl;
    }
    else if(ind == Schedule.getcapacity())
    {
        cout<<"Closest train is: "<< min<<endl;
    }
    else
    {
        cout<< "No such train"<<endl;
    }
}

void Trainschedule::findTrainByDepartureTime(Time t)
{
    int found = 1;
    for (int i = 0; i < Schedule.getcapacity(); i++) 
    {
        if (Schedule.get(i).getDepartureTime() == t) 
        {
            showTrainScheduleData(i);
            found++;
        }
    }
}

void Trainschedule::showTrainScheduleData()
{
    for (int i = 0; i < TrainAmount; i++)
    {
        showTrainScheduleData(i);
    }
}
void Trainschedule::showTrainScheduleData(int i)
{
    cout<<i+1<<") Train"<<"Departure time: "<<Schedule.get(i).getDepartureTime()<<" Destination: "<<Schedule.get(i).getDestination()<<" Peron № "<<Schedule.get(i).getPeron()<<endl;
}

void Trainschedule::addTrainInfos(int amount)
{
    try
    {
        for (int i = 0; i < amount; i++)
        {
            string TestPeron;
            string destination;
            Time departureTime;
            cout<<TrainAmount + 1<<" Train"<<endl;
            cout<<"Where train is going:";
            cin>>destination;
            cout<<"Which peron train is located on:";
            cin>>TestPeron;
            int Peron = check_number(TestPeron);
            cout<<"Enter this way:  <hour minute second>  with whitespaces beetween!"<<endl;
            cout<<"When does train arrive:";
            cin>>departureTime;
            TrainInfo temp(departureTime,destination,Peron);
            Schedule.push(temp);
            TrainAmount ++;
        
        }
    }
    catch(const std::exception& e)
    {
        if (amount - TrainAmount == 1)
        {
            std::cerr << e.what() << '\n';
            addTrainInfos(amount-TrainAmount);
            
        }
        else
        {
            std::cerr << e.what() << '\n';
            addTrainInfos(amount);
        }
    }
}
void Trainschedule::editData(int i)
{
    string TestChoice;
    cout<<"Which data do you want to edit?"<<endl;
    cout<<"1.Destination"<<endl;
    cout<<"2.Peron"<<endl;
    cout<<"3.Departure time"<<endl;
    cin>>TestChoice;
    int choice = check_number(TestChoice);
    if (choice == 1)
    {
        string destination;
        cout<<"Enter destination: ";
        cin>>destination;
        Schedule[i].setDestination(destination);
    }
    else if(choice == 2)
    {
        string TestPeron;
        cout<<"Enter peron: ";
        cin>>TestPeron;
        int peron = check_number(TestPeron);
        Schedule[i].setPeron(peron);
    }
    else if(choice == 3)
    {
        Time tim;
        cout<<"Enter time this way:  <hour minute second>  with whitespaces beetween!"<<endl;
        cin>>tim;
        Schedule[i].setDepartureTime(tim);
    }
}
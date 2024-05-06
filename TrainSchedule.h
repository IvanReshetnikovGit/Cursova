#pragma once
#include "TrainInfo.h"
#include "vectorClass.cpp"
class Trainschedule : TrainInfo
{
    public:
    vectorClass<TrainInfo> Schedule;
    int TrainAmount = 0;
    void closestTrain(string Destination);
    void findTrainByDepartureTime(Time t);
    void showTrainScheduleData();
    void showTrainScheduleData(int i);
    void addTrainInfos(int amount);
    void editData(int i);
};
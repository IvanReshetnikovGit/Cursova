#include "TrainSchedule.h"
int main()
{
    Trainschedule trainschedule;
    try
    {
        while(true)
        {
            if (trainschedule.TrainAmount == 0)
            {
                string TestAmount;
                int amount;
                try
                {
                    cout<<"How many trains would you like to add: ";
                    cin>>TestAmount;
                    amount = check_number(TestAmount);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                trainschedule.addTrainInfos(amount);
                
            }
            else if (trainschedule.TrainAmount > 0)
            {
                int choice;
                cout<<"What would you like to do?"<<endl;
                cout<<"1.What Train departs on <this> time?"<<endl;
                cout<<"2.Show all trains."<<endl;
                cout<<"3.Add train to schedule."<<endl;
                cout<<"4.Edit train data"<<endl;
                cout<<"5.Closest train to <wanted destination>"<<endl;
                cout<<"6.exit"<<endl;
                cin>>choice;
                if (choice == 1)
                {
                    Time t;
                    cout<<"Enter this way:  <hour minute second>  with whitespaces beetween!"<<endl;
                    cout<<"Enter time train departs:";
                    cin>>t;
                    trainschedule.findTrainByDepartureTime(t);
                }
                else if(choice == 2)
                {
                    trainschedule.showTrainScheduleData();
                }
                else if(choice == 3)
                {
                    trainschedule.addTrainInfos(1);
                }
                else if(choice == 4)
                {
                    string testTrain;
                    
                    trainschedule.showTrainScheduleData();
                    cout<<"Which one to edit:";
                    cin>>testTrain;
                    try
                    {
                        int train = check_number(testTrain);
                        if (train < 0 || train > trainschedule.TrainAmount)
                            throw invalid_argument("Next time enter correct data!");
                        else
                            trainschedule.editData(train-1);
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
                else if(choice == 5)
                {
                    string destination;
                    cout<<"Write destination: ";
                    cin>>destination;
                    trainschedule.closestTrain(destination);
                }
                else if(choice == 6)
                {
                    break;
                }
                else
                {
                    cout<<"Enter correct option"<<endl;
                }
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
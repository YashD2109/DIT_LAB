#include <iostream>
#include <queue>

using namespace std;

queue<string>jobQueue;
void addJob(string job)
{
    jobQueue.push(job);
    cout<<"job \"" <<job <<"\""<<" added to the queue"<<endl;
}
void deleteJob()
{
    if(jobQueue.empty()) cout<<"Queue is Empty No job to delete \n";
    else
    {
        cout<<"job \"" <<jobQueue.front() <<"\""<<" from the queue"<<endl;
        jobQueue.pop();
    }
}

int main()
{
    while (true)
    {
        cout<<"\nJob Queue Simulation:\n";
        cout<<"1.Add Job \n";
        cout<<"2.Delete Job\n";
        cout<<"3.Exit\n";
        cout<<"Enter your Choice(1-3):";

        int ch;
        string job;
        cin>>ch;
        switch(ch)
        {
        case 1:
            //string job;
            cout<<"Enter Job Name : \n";
            cin.ignore();
            getline(cin,job);
            addJob(job);
            break;
        case 2:
            deleteJob();
            break;
        case 3:
            cout<<"Exiting the Program. \n";
            exit(0);
        }
    }
    return 0;
}
#include<iostream>
using namespace std;

class Time
{
    int hours;
    int minutes;
    int seconds;

public:
    Time()
    {
        this->hours = 0;
        this->minutes = 0;
        this-> seconds = 0; 
    }

    Time(int hours, int minutes, int seconds)
    {
        this->hours = hours;
        this->minutes = minutes;
        this-> seconds = seconds; 
    }
    
   void sethours(int t)
    {
        this->hours = t;
    }

    void setminutes(int t)
    {
        this->minutes = t;
    }

    void setseconds(int t)
    {
        this->seconds = t;
    }
    int gethours()
    {
        return this->hours;
    }

    int getminutes()
    {
        return this->minutes;
    }

    int getseconds()
    {
        return this->seconds;
    }

 

    void accepttime()
    {
        int h;
        int m;
        int s;
        cout<<"-------------------------"<<endl;
        cout<<"Enter Hours:"<<endl;
        cin>>h;
        sethours(h);
        cout<<"Enter Minutes:"<<endl;
        cin>>m;
        setminutes(m);
        cout<<"Enter Seconds:"<<endl;
        cin>>s;
        setseconds(s);
        cout<<"-------------------------"<<endl;
    }

    void displayTime()
    {
        cout<<"-------------------------"<<endl;
        cout<<"Time: "<<gethours()<<" : "<<getminutes()<<" : "<<getseconds()<<endl;
        cout<<"-------------------------"<<endl;
    }
};

int main()
{
    Time **ptr = new Time *[5];
    for(int i=0; i<5; i++)
    {
        ptr[i] = new Time;
    }

    for(int i=0; i<5; i++)
    {
        ptr[i]->accepttime();
        ptr[i]->displayTime();
    }
}

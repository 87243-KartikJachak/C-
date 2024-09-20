#include<iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void acceptDate()
    {
        cout<<"Enter your Date of Birth: "<<endl;
        cout<<"Enter day: "<<endl;
        cin>>day;
        cout<<"Enter month: "<<endl;
        cin>>month;
        cout<<"Enter year: "<<endl;
        cin>>year;
    }

    void displayDate()
    {
        cout<<day<<" / "<<month<<" / "<<year<<endl;
    }
};

class Person
{
    string name;
    string address;
    Date dob; //Composition of dob Object

public:
    Person()
    {
        this->name = "";
        this->address = "";
    }

    Person(string name, string address, int day, int month, int year): dob(day, month, year)
    {
        this->name = name;
        this->address = address;
    }

    void acceptPerson()
    {
        // getchar();
        cout<<"Enter name: "<<endl;
        getline(cin, name);
        cout<<"Enter address: "<<endl;
        getline(cin, address);
        dob.acceptDate();
    }

    void displayPerson()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Date of Birth: "<<endl;
        dob.displayDate();
    }
};


int main()
{
    Person p1;
    p1.acceptPerson();
    p1.displayPerson();

    return 0;
}
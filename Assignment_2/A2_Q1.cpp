#include<iostream>
using namespace std;

class Date
{
public:
    int day;
    int month;
    int year;

    void initDate()
    {
        day = 25;
        month = 15;
        year = 2023;
    }

    void acceptDateFromConsole()
    {
        cout<<"Enter day, month and year: "<<endl;
        cin>>day>>month>>year;
    }

    void printDateOnConsole()
    {
        cout<<"Date: "<<day<<"/"<<month<<"/"<<year<<endl; 
    }

    void checkForLeapYear()
    {
        if(year % 4 == 0 && year % 400 == 0)
        {
            cout<<"Is a leap year"<<endl;
        } 
        else 
        {
            cout<<"Not a leap year"<<endl;
        }
    }
};


int main()
{
    Date d1;
    int choice;

    cout<<"-------------MENU----------------"<<endl;
    cout<<"1. Inital Date"<<endl;
    cout<<"2. Accept and Display Date"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"------------------------"<<endl;

    do
    {
        cout<<"Please enter your choice: "<<endl;
        cin>>choice;

        switch (choice)
        {
            case 1:
                d1.initDate();
                d1.printDateOnConsole();
                d1.checkForLeapYear();
            break;

            case 2:
                d1.acceptDateFromConsole();
                d1.printDateOnConsole();
                d1.checkForLeapYear();
            break;

            case 3:
                exit(0);
            break;

        default:
            cout<<"Please try Again"<<endl;
            break;
        }    
    } while (choice!=3);
}
#include<iostream>
using namespace std;

class TollBooth
{
    double toll_amount;
    int count;

public:
    TollBooth()
    {
        this->toll_amount = 0;
        this->count = 0;
    }

    void Menu()
    {        
        cout<<"TollBooth---------------"<<endl;
        cout<<"1. Paying Car"<<endl;
        cout<<"2. Non Paying Car"<<endl;
        cout<<"3. Revenue"<<endl;
        cout<<"4. Report"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"------------------------"<<endl;
    }

    void paying_Cars()
    {
        this->toll_amount = this->toll_amount + 0.5;
        this->count = this->count + 1;       
    } 

    void Non_paying_cars()
    {
        this->count = this->count + 1;       
    }

    void tollBoothDisplay() 
    {
        cout<<"Welcome!!-------"<<endl;
        cout<<"Number of cars passed: "<< this->count<<endl;
        cout<<"Total revenue: "<<this->toll_amount<<endl;
        cout<<"------------------------"<<endl;
    }

    void RevenueAmout()
    {
        cout<<"Revenue: "<<this->toll_amount<<endl;
    }

};


int main()
{
    int choice;
    TollBooth tb;
    tb.Menu();
    do
    {
        cout<<"Please enter your choice: "<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            tb.paying_Cars();
            tb.tollBoothDisplay();
            tb.Menu();
        break;

        case 2:
            tb.Non_paying_cars();
            tb.tollBoothDisplay();
            tb.Menu();
        break;

        case 3:
            tb.RevenueAmout();
            tb.Menu();
        break;

        case 4:
            tb.tollBoothDisplay();
            tb.Menu();
        break;

        case 5:
                exit(0);
        break;

        default:
                cout<<"Please Try Again!!"<<endl;
            break;
        }
    } while(choice!=5);
}
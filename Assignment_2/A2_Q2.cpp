#include<iostream>
using namespace std;

class Student
{
    int roll;
    string name;
    int marks;

public:
    void initStudent()
    {
        roll = 12;
        name = "Kartik Jachak";
        marks = 75;
    }

    void acceptstudentOnConsole()
    {
        cout<<"Enter student roll: "<<endl;
        cin>>roll;
        cout<<"Enter student name: "<<endl;
        //cin>>name;
        cin.ignore();
        getline(cin, name);
        cout<<"Enter student marks: "<<endl;
        cin>>marks;
    }

    void printStudentOnConsole()
    {
        cout<<"Roll No: "<<roll<<endl;
        cout<<"Student Name: "<<name<<endl;
        cout<<"Marks: "<<marks<<endl;
        cout<<"------------------------"<<endl;
    }
};

int main()
{
    Student s1;
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
                s1.initStudent();
                s1.printStudentOnConsole();
            break;

            case 2:
                s1.acceptstudentOnConsole();
                s1.printStudentOnConsole();
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
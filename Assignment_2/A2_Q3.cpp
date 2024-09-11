#include <iostream>
using namespace std;

namespace NA
{
    class Student
    {
    private:
        int rollno;
        string name;
        int marks;

    public:
        void initStudent() // default values for data members (0,” ”,0);
        {
            this->rollno = 0;
            this->name = "  ";
            this->marks = 0;
        }

        void printStudentOnConsole()
        {
            cout << "+--------------------------------------+" << endl;
            cout << "Rollno : " << this->rollno << endl;
            cout << "Name   : " << this->name << endl;
            cout << "Marks  : " << this->marks << endl;
            cout << "+--------------------------------------+" << endl;
        }

        void acceptStudentFromConsole()
        {
            cout << "Enter the Rollno : ";
            cin >> this->rollno;
            cout << "Enter the Name : ";
            // cin >> this->name;
            cin.ignore();
            getline(cin, name);
            cout << "Enter the Marks : ";
            cin >> this->marks;
        }
    };
}
int menu()
{
    int choice;
    cout << "Enter the choice :" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Init Data" << endl;
    cout << "2. ADD Data" << endl;
    cout << "3. DISPLAY Data" << endl;
    cin >> choice;
    return choice;
}

int main()
{

    // using namespace NA;
    int choice;
    NA::Student s1;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            s1.initStudent();
            break;

        case 2:
            s1.acceptStudentFromConsole();
            break;

        case 3:
            s1.printStudentOnConsole();
            break;

        default:
            cout << "Invalid Input !!!" << endl;
            break;
        }
    }

    return 0;
    return 0;
}
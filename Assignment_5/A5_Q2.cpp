#include<iostream>
using namespace std;

class Marks
{
    int physics;
    int computers;
    int chemistry;

public:
    Marks()
    {
        this->physics = 0;
        this->computers = 0;
        this->chemistry = 0;
    }

    Marks(int day, int month, int year)
    {
        this->physics = physics;
        this->computers = computers;
        this->chemistry = chemistry;
    }

    void setphysics(int p)
    {
        this->physics = p;
    }

    void setchemistry(int ch)
    {
        this->chemistry = ch;
    }

    void setcomputers(int co)
    {
        this->computers = co;
    }

    int getphysics()
    {
        return this->physics;
    }

    int getcomputers()
    {
        return this->computers;
    }

    int getchemistry()
    {
        return this->chemistry;
    }


    void acceptMarks()
    {
        int physics;
        int computers;
        int chemistry;
        cout<<"Enter your Marks Subject-wise: "<<endl;
        cout<<"Enter physics marks: "<<endl;
        cin>>physics;
        setphysics(physics);
        cout<<"Enter computers marks: "<<endl;
        cin>>computers;
        setcomputers(computers);
        cout<<"Enter chemistry marks: "<<endl;
        cin>>chemistry;
        setchemistry(chemistry);
    }

    void displayMarks()
    {
        double percentage;
        cout<<"Physics: "<<getphysics()<<endl;
        cout<<"Computer: "<<getcomputers()<<endl;
        cout<<"Chemistry: "<<getchemistry()<<endl;
        percentage = (physics + computers + chemistry/300) * 100;
        cout<<"---------------------------------"<<endl;
        cout<<"Percentage: "<<percentage<<endl;
    }
};

class Student
{
    const int roll; // Auto Generated
    string name;
    string gender;
    static int generate_rollno;
    Marks marks;

public:
    Student() : roll(++generate_rollno) //Similar to roll = ++generate_rollno
    {
        name = "";
        gender = "";
    }

    Student(string name, string gender, int physics, int computers, int chemistry) : roll(++generate_rollno), marks(physics, computers, chemistry) //Similar to roll = ++generate_rollno
    {
        this->name = name;
        this->gender = gender;
    }

    void setroll(int gr)
    {
        this->generate_rollno = gr;
    }

    void setname(string n)
    {
        this->name = n;
    }

    void setgender(string g)
    {
        this->gender = g;
    }

    string getname()
    {
        return this->name;
    }

    string getgender()
    {
        return this->gender;
    }

    int getroll()
    {
        return this->generate_rollno;
    }

    void AcceptStudent()
    {
        string name;
        string gender;
        cout<<"Enter your Name: "<<endl;
        getline(cin, name);
        setname(name);
        cout<<"Enter your Gender: "<<endl;
        getline(cin, gender);
        getgender();
        marks.acceptMarks();       
    }

    void printStudent()
    {
        cout<<"---------------------------"<<endl;
        cout<<"Name: "<<getname()<<endl;
        cout<<"Gender: "<<getname()<<endl;
        cout<<"Marks(subject-wise): "<<getname()<<endl;
        marks.displayMarks();
        cout<<"---------------------------"<<endl;
    }

    int searchStudent(Student **arr[])
    {
        for(int i=0; i<=5; i++)
        {
            if(roll == arr[i]->getroll())
            {
                return i
            }
            else
            {
                return -1;
            }
        }   
    }
};

int menu()
{
    int choice;
    cout << "Student details :- ";
    cout << "1. Exit"<<endl;
    cout << "2. Add Student"<<endl;
    cout << "3. Print All Students"<<endl;
    cout << "4. Search Student by Roll Number"<<endl;
    cout << "Enter your choice: "<<endl;
    cin >> choice;
    return choice;
}

int Student::generate_rollno = 200;

int main()
{
    int choice;

    Student *arr[5];
    int choice;

    while(choice=menu()!= 1)
    {
        switch (choice)
        {
        case 1:
            exit(0);
            break;

        case 2:
            for(int i=0; i<5; i++)
            {
                arr[i]->AcceptStudent();
            }
            break;

        case 3:
            for(int i=0; i<5; i++)
            {
                arr[i]->printStudent();
            }
            break;

        case 4:
                int roll;
                cout<<"Enter roll no to search: "<<endl;
                cin>>roll;

                int i;
                i = arr[i]->searchStudent(arr,roll);
                if (i >=0) {
                    arr[i]->printStudent();
                } else {
                    cout << "Student with roll number " << roll << " not found." << endl;
                }
                break; 
        default:
                cout<<"Please Try Again"<<endl;
            break;
        }
    }

}

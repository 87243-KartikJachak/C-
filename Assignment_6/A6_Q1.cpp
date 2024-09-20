#include <iostream>
using namespace std;

class Date
{
	private:
		
	int day;
	int month;
	int year;
	
	public:
		Date()
		{
			this->day = 0;
			this->month= 0;
			this->year = 0;
		}
		
		void acceptDate()
		{
			cin >> day >> month >> year;
		}
		void displayDate()
		{
			cout <<this->day <<" / "<< this->month <<" / "<< this->year << endl;
		}	
};

class Person{
	
	private:
		string name;
		string address;
		Date *bd;
		
	public:	
		
		Person()
		{
			this->name = "NA";
			this->address = "NA";
			bd = NULL;
		}
		void acceptPerson()
		{
			cout<<"Enter Data: "<< endl;
			cout <<"Enter Name: "; cin >> name;
			cout<<"Enter Address: "; cin >> address;
//			acceptBirthDate();
		}	
		
		void displayPerson()
		{
			cout<< "Name: " << this->name << endl;
			cout<< "Address: " << this->address << endl;
			if(bd!=NULL)
			{
				cout<<"Date of Birth is: ";
				bd->displayDate() ;
			}
		}
		
		void acceptBirthDate()
		{
			bd = new Date;
			cout <<"Enter Date of Birth: "<<endl;
			bd->acceptDate();
		}
		
		~Person()
		{
			if(bd!=NULL)
			{
				delete bd;
				bd = NULL;
			}
		}
	
};

class Employee: public Person{
	
	private:
		int empid;
		double sal;
		string dept;
		Date jd;
		
	public:
		
		void acceptEmployee()
		{
			acceptPerson();
			cout<<"Enter Employee ID: "; cin >> empid;
			cout <<"Enter Salary: "; cin >> sal;
			cout<<"Enter Department: "; cin >> dept;
			cout<<"Enter Joining Date: "; jd.acceptDate(); 	
		}	
		
		void displayEmployee()
		{
			
			cout << endl << endl;
			displayPerson();
			
			cout<< "EmpId: " << this->empid << endl;
			cout<<"Salary: "<< this->sal << endl;
			cout<<"Dept: "<< this->dept << endl;
			cout <<"Joining Date is: ";
			jd.displayDate();
			cout << endl;
		}	
};

int main()
{
	Employee e1;
	e1.acceptEmployee();
	e1.acceptBirthDate();
	cout << "Employee Details: "<<endl;
	e1.displayEmployee();
	
}
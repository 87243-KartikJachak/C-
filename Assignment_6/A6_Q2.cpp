#include <iostream>
using namespace std;

class Employee{
	
	private:
		int id;
		double salary;
		
	public:
		Employee()
		{
			this->id = 0;
			this->salary = 0;
		}	
		Employee(int id, double salary)
		{
			this->id = id;
			this->salary = salary;
		}
		void setId(int id)
		{
			this->id = id;
		}
		int getId()
		{
			return id;
		}
		void setSalary(double salary)
		{
			this->salary = salary;
		}
		int getSalary()
		{
			return salary;
		}
		void acceptEmployee()
		{
			cout<<"Enter EmpID: "; cin >> id;
			cout<<"Enter Salary: "; cin >> salary;	
		}
		void displayEmployee()
		{
			cout<<"EmpID: "<<id<<endl;
			cout<<"Salary: "<<salary<<endl;
		}
};

class Manager: virtual public Employee{
	
	private:
		double bonus;
	
	public:
		Manager()
		{
			this->bonus = 0;
		}
		void acceptManager()
		{
			cout <<"Enter Data for Manager: "<<endl;
			acceptEmployee();
			setBonus();
		}
		void setBonus()
		{
			cout<<"Enter Bonus: ";
			cin >> bonus;
		}
		void displayManager()
		{
			displayEmployee();	
			displayBonus();
		}
		void displayBonus()
		{
			cout<<"Bonus: ";
			cout<< bonus << endl;
		}
};

class Salesman: virtual public Employee{
	
	private:
		double commission;
	
	public:
		
		Salesman()
		{
			this->commission = 0;
		}	
		void acceptSalesman()
		{
			cout<<"Enter Data for SalesMan: "<< endl;
			acceptEmployee();
			setCommission();
		}
		void setCommission()
		{
			cout<<"Enter Commission: "; 
			cin >> commission;
		}
		void displaySalesman()
		{
			displayEmployee();
			displayCommission();	
		}
		void displayCommission()
		{
			cout << "Commission: "<<commission<<endl;
		}
		
};

class SalesManager: public Salesman, Manager{
	
	public:
		void acceptSalesManager()
		{
			cout<<"Enter data for SalesManager: "<< endl;
			acceptEmployee();
			setCommission();
			setBonus();
		}
		void DisplaySalesManager()
		{
			cout<<"Entered data for SalesManager: "<< endl;
			displayEmployee();
			displayCommission();
			displayBonus();
		}
};

int main()
{
	cout<<"Who's data you want to enter: "<<endl;
	cout<<"1. Manager"<< endl <<"2. Salesman"<<endl<<"3. SalesManager"<<endl;
	cout << endl << "Your Choice: ";
	int ch;
	cin >> ch;
	
	if(ch == 1)
	{
		Manager m;
		m.acceptManager();
		m.displayManager();
	}
	else if(ch == 2)
	{
		Salesman s;
		s.acceptSalesman();
		s.displaySalesman();
	}
	else if(ch == 3)
	{
		SalesManager sm;
		sm.acceptSalesManager();
		sm.DisplaySalesManager();
	}
	else
	cout<<"Terminated because of wrong choice :(";
	
	
}

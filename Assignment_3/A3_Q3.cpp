#include <iostream>
using namespace std;

class address{
	
	private:
		string building;
		string street;
		string city;
		int pin;
	
	public:
		address()
		{
			this->building = " ";
			this->street = " ";
			this->city = " ";
			this->pin = 0;
		}

		void setBuilding(string s)
		{
			this->building = s;
		}
	    void setStreet(string s)
	    {
	    	this->street = s;
		}
		void setCity(string s)
		{
			this->city = s;
		}
		void setPin(int x)
		{
			this->pin = x;
		}
		string getBuilding()
		{
			return this->building;
		}
		string getStreet()
		{
			return this->street;
		}
		string getCity()
		{
			return this->city;
		}
		int getPin()
		{
			return this->pin;
		}
		
		
		void acceptAddress()
		{
			string bld;
	     	string strt;
		    string cty;
			int pn;
			
			cout <<"Enter Building Name: ";
			getline(cin, bld);
			setBuilding(bld);
			cout<<"Enter Street Name: ";
			getline(cin, strt);
			setStreet(strt);
			cout <<"Enter City Name: ";
			cin >> cty;
			setCity(cty);
			cout<<"Enter PinCode: ";
			cin >> pn;
			setPin(pn);
		 	
		}
		void displayAddress()
		{
			cout << getBuilding() << ", " <<getStreet()<<", "<< getCity() <<", "<< getPin() ;
		}		
};


int main()
{
	address ad1;
	ad1.acceptAddress();
	ad1.displayAddress();
}

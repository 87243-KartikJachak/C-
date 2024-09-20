#include <iostream>
using namespace std;

enum EAccountType
{
    Saving,
    Current,
    DMAT
};


class InSufficientFundsException
{
    int accno;
    double currentBalance;
    double withdrawAmount;

public:

    InSufficientFundsException(int accno, double currentBalance, double withdrawAmount)
    {
        this->accno=accno;
        this->currentBalance=currentBalance;
        this->withdrawAmount=withdrawAmount;
    }

    void display()
    {
        if(withdrawAmount < 0)
        {
            cout<<"Amount is negative: "<<withdrawAmount<<endl;
        }
        if(currentBalance < withdrawAmount)
        {
            cout<<"Insufficient funds!";   
        }
    }       
};
int accTypemenu()
{
    int choice;
    cout << "\t-------------------------------" << endl;
    cout << "\tChoose Type of Account....? " << endl;
    cout << "\t\t1. Saving" << endl;
    cout << "\t\t2. Current" << endl;
    cout << "\t\t3. Dmat" << endl;
    cout << "\tEnter your choice - ";
    cin >> choice;
    cout << "\t-------------------------------" << endl;
    return choice;
}

class Account
{
	const int accno;
	string accountType;
	double balance;
	static int generateAccNO;
	public : 
	    Account():accno(++generateAccNO)
	    {
	    	this->accountType;
	    	this->balance;
		}
		
        Account(string accountType,double balance):accno(++generateAccNO)
	    {
	    	this->accountType=accountType;
	    	this->balance=balance;
		}
		
        void setAccountType(string accountType)
		{
			this->accountType=accountType;
		}
		
        void setBalance(double balance)
		{
			this->balance=balance;
		}
		
        string getAccountType()
		{
			return accountType;
		}
		
        double getBalance()
		{
			return balance;
		}
		
        int getAccno()
		{
			return accno;
		}
		
		void accept()
		{
			int choice;
			double balance;
			string accountType;
			cout<<"Enter Account Details : "<<endl;
			cout<<"Account Number: "<<getAccno()<<endl;
			cout<<"Account Type: "<<endl;
			// choice = accTypemenu();
            switch(choice = accTypemenu())
            {
                case Saving:
                    accountType="Saving";
                    break;
                case Current:
                    accountType="Current";
                    break;
                case DMAT:
                    accountType="Dmat";
                    break;
                default:
                    accountType="Not Defined";
                    break;
            }

		    setAccountType(accountType);
			cout<<"\tAccount Balance : ";
			cin>>balance;
			setBalance(balance);
		}
		
        void display()
		{
		    cout<<"Account Details : "<<endl;
			cout<<"\tAccount Number  : "<<getAccno()<< endl;
			cout<<"\tAccount Type    : "<<getAccountType()<< endl;
			cout<<"\tAccount Balance : "<<getBalance()<< endl;	
		}

		void deposit(double amount)
		{
			double balance=getBalance();
			if(amount<0)
			  throw InSufficientFundsException(accno,balance,amount);
			else
			{
				balance=balance+amount;
				setBalance(balance);
				cout << "********************************" << endl;
				cout<<"Amount Deposited"<<endl;
			}
		}
		void withdraw(double amount)
		{
			double balance=getBalance();
			if(balance<amount)
			  throw InSufficientFundsException(accno,balance,amount);
			else
			{
				balance=balance-amount;
				setBalance(balance);
				cout << "********************************" << endl;
				cout<<"Amount withdrawed"<<endl;
			}
		}
};

int Account :: generateAccNO=1000;

enum AccountMenu
{
    New_Account,
    Deposit,
    Withdraw,
    Display,
    Exit
};

int amenu()
{
    int choice;
    cout << "-----------------------------------" << endl;
    cout << "\t1. Create New Account" << endl;
    cout << "\t2. Deposit Money" << endl;
    cout << "\t3. Withdraw Money" << endl;
    cout << "\t4. Display Account Details" << endl;
    cout << "\t5. Exit" << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    cout << "------------------------------------" << endl;
    return choice;
}



int findAccount(Account *arr[], int index)
{
	int an;
	cout<<"Enter Your Account Number : ";
	cin >> an;
	for(int i=0;i<=index;i++)
	{
		if(an == arr[i]->getAccno())
		return i;
	}
	return -1;
}

int main()
{
    Account *arr[5];
    int index=0,choice,temp=0;
    double balance,amount;

    while(choice == amenu()!=Exit)
    {
        switch (AccountMenu(choice))
        {
        case New_Account:
            {
                if(index < 5)
                {
                    arr[index] = new Account;
                    arr[index]->accept();
                }
            }
        break;

        case Deposit:
            {
                temp = findAccount(arr,index);
                if(temp!= -1)
                {
                    cout<<"Enter amount to deposit: "<<endl;
                    cin>>amount;
                    arr[temp]->deposit(amount);
                }
            }
        break;

        case Withdraw:
            {
                temp = findAccount(arr,index);
                if(temp!= -1)
                {
                    cout<<"Enter amount to withdraw: "<<endl;
                    cin>>amount;
                    arr[temp]->withdraw(amount);
                }
            }
        break;

        case Display:
            {
                temp = findAccount(arr,index);
                if(temp!= -1)
                {
                    arr[temp]->display();
                }
            }
        break;

        default:
                cout << "Invalid choice ! " << endl;
            break;
        }
    }
}
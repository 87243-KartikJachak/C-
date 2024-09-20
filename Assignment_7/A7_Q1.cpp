#include <iostream>
#include <typeinfo>
using namespace std;

class Product 
{
    int id;
    string title;
    double price;

public :
    Product()
    {
        this->id = 0;
        this->price = 0;
        this->title = "";
    }

    Product(int id, string title, int price)
    {
        this->id = id;
        this->title = title;
        this->price = price;
    }

    int getprice()
    {
        return this->price;
    }

    virtual void accept()
    {
        cout<<"Enter Id: "<<endl;
        cin>>id;
        getchar();
        cout<<"Enter Title: "<<endl;
        getline(cin, title);
        cout<<"Enter price: "<<endl;
        cin>>price;
    }

    virtual void display()
    {
        cout<<"---------------------"<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"---------------------"<<endl;
    }
};

class Book: public Product
{
    string author;

public:
    Book()
    {
        this->author = "";
    }
    
    Book(string author)
    {
        this->author = author;
    }

    void accept()
    {
        Product::accept();
        getchar();
        cout<<"Enter Author: "<<endl;
        getline(cin, author);
    }

    void display()
    {
        // cout<<"---------------------"<<endl;
        Product::display();
        cout<<"Author: "<<author<<endl;
        cout<<"---------------------"<<endl;
    }
};

class Tapes: public Product
{
    string artist;

public:
    Tapes()
    {
        this->artist = "";
    }
    
    Tapes(string artist)
    {
        this->artist = artist;
    }

    void accept()
    {
        Product::accept();
        getchar();
        cout<<"Enter Artist: "<<endl;
        getline(cin, artist);
    }

    void display()
    {
        // cout<<"---------------------"<<endl;
        Product::display();
        cout<<"Artist: "<<artist<<endl;
        cout<<"---------------------"<<endl;
    }
};

double calculatebill(Product** arr)
{
    double total = 0;
    for(int i=0; i<3; i++)
    {
        if(typeid(*arr[i])==typeid(Book) || typeid(*arr[i])==typeid(Tapes))
        {
             total += (arr[i]->getprice() * 0.90);            
        }
    }

    return total;
}

int main()
{
    Product* arr[3];
    int choice;

        cout<<"---------------------"<<endl;
        cout<<"1. Add Product"<<endl;
        cout<<"2. Display Product"<<endl;
        cout<<"3. Total Bill"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"---------------------"<<endl;
    
    do
    {
        cout<<"Enter your choice: "<<endl;    
        cin>>choice;

        switch (choice)
        {
        case 1:
            int ch;
            for(int i=0; i<3; i++)
            {
                cout<<"Enter 1 to add Book or Enter 0 for Tapes:"<<endl;
                cin>>ch;

                if(ch == 1)
                {
                    arr[i] = new Book;
                    arr[i]->accept();
                }
                else
                {
                    arr[i] = new Tapes;
                    arr[i]->accept();
                }
            }
            break;
        
            case 2:
            cout<<"Your Products:"<<endl;
            for(int i=0; i<3; i++)
            {
                arr[i]->display();
            }
            break;

            case 3:
                cout << "Total bill after discount: " << calculatebill(arr) << endl;
            break;

            case 4:
                exit(0);
            break;

        default:
                cout<<"Please Try Again!!"<<endl;
            break;
        }
    } while (choice!=4);
    
    return 0;
}

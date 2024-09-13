#include<iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int capacity;  

public:
    Stack(int size = 5)
    {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isFull()
    {
        return top == capacity - 1; 
    }

    bool isEmpty()
    {
        return top == -1;
    }    

    void Push(int item)
    {
        if(isFull())
        {
            cout<<"Stack Full! unable to push elements in to the stack"<<endl; 
        }
        else 
        {
            arr[++top] = item;
        }
    }

    void Pop()
    {
        if (isEmpty())
        {
            cout<<"Stack is empty!!"<<endl;
            // return -1;
        }
        arr[top--];
    }

    int Peek()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty!!"<<endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    void printStack()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty!!"<<endl;
        }
        else
        {
            for(int i=top; i>=0; --i)
            {
                cout<<"Elements pushed: "<<endl;
                cout<<arr[i]<<endl;
            }
        }
    }
};


int main()
{
    Stack *s = new Stack(5);

    s->Push(10);    
    s->Push(20);    
    s->Push(30);    
    s->Push(40);    
    s->Push(50);

    // s.Push(60);
    
    s->printStack();
    cout<<"Element Popped from stack!!"<<endl;
    s->Pop();
    s->Pop();
    cout<<"Top Stack: "<<endl;
    s->Peek();
    cout<<s->Peek()<<endl;
    //s.printStack();
}

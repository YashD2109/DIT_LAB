#include <iostream>
using namespace std;

const int MAX_SIZE=10;
class deque
{
    private:
        int dequeArray[MAX_SIZE]={};
        int front,rear;
    public:
        deque()
        {
            front=rear=-1;
        }

        bool isEmpty()
        {
            return front==-1 && rear==-1;
        }

        bool isFull()
        {
            return (rear-1)%MAX_SIZE==front;
        }

        void addFront(int value)
        {
            if(isFull()) cout<<"Cant't add elements Deque is Full\n";
            else 
            {
                if(isEmpty()) front=rear=0;
                else front=(front-1+MAX_SIZE)%MAX_SIZE;
            
            dequeArray[front]=value;
            cout<<"Element "<<value<<" added at the front.\n";
            }
        }

        void addEnd(int value)
        {
            if(isFull()) cout<<"Cant't add elements Deque is Full\n";
            else 
            {
                if(isEmpty()) front=rear=0;
                else rear=(rear+1+MAX_SIZE)%MAX_SIZE;
            
            dequeArray[rear]=value;
            cout<<"Element "<<value<<" added at the end.\n";
            }
        } 

        void deleteFront()
        {
            if(isEmpty()) cout<<"Deque is already empty.\n";
            else
            {
                cout<<"Element "<<dequeArray[front]<<" delete from the front.\n";
                if(front==rear) front=rear=-1;
                else front=(front+1)%MAX_SIZE;
            }
        } 

        void deleteRear()
        {
            if(isEmpty()) cout<<"Deque is already empty.\n";
            else
            {
                cout<<"Element "<<dequeArray[rear]<<" delete from the front.\n";
                if(front==rear) front=rear=-1;
                else rear=(front+1)%MAX_SIZE;
            }
        } 

        void displayDeque()
        {
            if(isEmpty()) cout<<"Dequeue is Empty.\n";
            else 
            {
                cout<<"Deque Elements: ";
                int i=front;
                while(true)
                {
                    cout<<dequeArray[i]<<" ";
                    if(i==rear) break;
                    i=(i+1)%MAX_SIZE;
                }
                cout<<endl;
            }
        }
};

int main()
{
    deque myDeque;
    int value;
    while(true)
    {
        cout<<"\nDeque Simulation: \n";
        cout<<"1.Add Element at Front \n";
        cout<<"2.Add Element at End \n";
        cout<<"3.Delete Element at Front \n";
        cout<<"4.Delete Element at End \n";
        cout<<"5.Display Dequeue\n";
        cout<<"6.Exit\n";
        cout<<"Enter your Choice: \n";
        int ch;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter the Element to Add at Front: ";
            cin>>value;
            myDeque.addFront(value);
            break;
        case 2:
            cout<<"Enter the Element to Add at End: ";
            cin>>value;
            myDeque.addEnd(value);
            break;
        case 3:
            myDeque.deleteFront();
            break;
        case 4:
            myDeque.deleteRear();
            break;
        case 5:
            myDeque.displayDeque();
            break;
        case 6:
            exit(0);
            break;
        }
    }
    return 0;
}
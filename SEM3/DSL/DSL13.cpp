#include <iostream>
using namespace std;

const int MAX_ORDERS=5;

class CircularQueue
{
private:
    int queueArray[MAX_ORDERS];
    int front,rear;
public:
    CircularQueue()
    {
        front=rear=-1;
    }
    
    bool isEmpty()
    {
        return front==-1 && rear==-1;
    }
    
    bool isFull()
    {
        return (rear+1)%MAX_ORDERS==front;
    }

    void placeOrder(int orderNumber)
    {
        if(isFull()) cout<<"Maximum orders reaches. Can't placeemore orders.\n";
        else
        {
            if(isEmpty()) front=rear=0;
            else rear=(rear+1)%MAX_ORDERS;
        
        queueArray[rear]=orderNumber;
        cout<<"Order "<<orderNumber<<" Placed Successfully.\n";
        }
    }

    void serveOrder()
    {
        if(isEmpty()) cout<<"No orders to serve.The Queue is Empty.\n";
        else
        {
            cout<<"Order "<<queueArray[front]<<" searved.\n";
            if(front==rear) front=rear=-1;
            else front=(front+1)%MAX_ORDERS;
        }
    }

    void displayOrders()
    {
        if(isEmpty()) cout<<"No Order in the Queue.\n";
        else
        {
            cout<<"Orders in queue: ";
            int i=front;
            while(true)
            {
                cout<<queueArray[i]<<" ";
                if(i==rear) break;
                i=(i+1)%MAX_ORDERS;
            }
            cout<<endl;
        }
    }
};

int main()
{
    CircularQueue orderQueue;
    while(true)
    {
        cout<<"\nPizza Parlor Simulation: \n";
        cout<<"1.Place Order\n";
        cout<<"2.Serve Order\n";
        cout<<"3.Display Orders\n";
        cout<<"4.Exit\n";
        cout<<"Enter Your Choice: \n";
        int ch;
        cin>>ch;
        switch(ch)
        {
        case 1:
            int orderNumber;
            cout<<"Enter Order Number: \n";
            cin>>orderNumber;
            orderQueue.placeOrder(orderNumber);
            break;
        case 2:
            orderQueue.serveOrder();
            break;
        case 3:
            orderQueue.displayOrders();
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}
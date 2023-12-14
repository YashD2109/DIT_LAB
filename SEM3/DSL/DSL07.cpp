#include <iostream>
using namespace std;

class node
{
    int v;
    int data;
    string name;
    node *next;

public:
    node *create(node *);
    void insert(node *);
    void display(node *);
    node *reverse(node *);
    void del(node *);
    void count(node *);
    void merge(node *,node *);
};

node *node::create(node *head)
{
    head=new node;
    head->data=0;
    head->next=NULL;
    return head;
}
void node::count(node* head)
{
    int count=0;
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    cout<<"\nTotal Nodes = "<<count;
}
void node::del(node *head)
{
    node *temp;
    temp=head;
    int d;
    cout<<"\nEnter the Location   \n";
    cin>>d;
    while(temp->next->data!=d) 
        temp=temp->next;
    node *t1;
    t1=new node;
    t1=temp->next;
    temp->next=t1->next;
    delete t1;
}
void node::insert(node *head)
{
    node *t1;
    t1=new node;
    node *temp;
    node *t;
    t=new node;
    temp=head;

    cout<<"\nEnter the PRN number \n";
    int g;
    cin>>g;
    cout<<"\nEnter the Name \n";
    string na;
    cin>>na;

    t->data=g;
    t->name=na;
    t->next=NULL;

    static int c=0;
    cout<<"\n1.Add memberts/president/secretary\n";
    char ch;
    cin>>ch;
    
    if(ch=='p')
    {
        if(temp->next==NULL) temp->next=t;
        else
        {
            t->next=temp->next;
            temp->next=t;
        }
    }
    if(ch=='s')
    {
        while(temp->next!=NULL) temp=temp->next;
        c++;
        temp->next=t;
    }
    if(ch=='m')
    {
        temp=head;
        if(c!=0)
        {
            while(temp->next->next !=NULL) temp=temp->next;
            t->next=temp->next;
            temp->next=t;
        }
        else
        {
            while(temp->next!=NULL) temp=temp->next;
            temp->next=t;
        }
    }
}
void node::display(node *head)
{
    node *temp;
    if(head->data !=0) temp=head;
    else temp=head->next;
    while(temp!=NULL)
    {
        cout<<"["<<temp->data<<" | "<<temp->name<<"] -> ";
        temp=temp->next;
    }
    if(temp==NULL) cout<<"NULL\n\n";
}
node* node::reverse(node *head)
{

    if(head->next==NULL)
        return head;
    node *rest=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
}
void node::merge(node *head,node*head1)
{
    node *curr;
    curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=head1->next;
}
int main()
{
    node *head,*head1;
    node s;
    head=new node;
    head1=new node;

    while(1)
    {
        cout<<"\n1: Create";
        cout<<"\n2:Insert";
        cout<<"\n3.Display";
        cout<<"\n4:Exit";
        cout<<"\n5:Reverse";
        cout<<"\n6:Delete";
        cout<<"\n7:Count";
        cout<<"\n8:Merge";
        cout<<"\nEnter Your Choice : ";
        int ch;
        cin>>ch;
        switch(ch)
        {
        case 1:
            head=s.create(head);
            break;
        case 2:
            s.insert(head);
            break;
        case 3:
            s.display(head);
            break;
        case 4:
            exit(0);
        case 5:
            head= s.reverse(head);
            s.display(head);
            break;
        case 6:
            s.del(head);
            break;
        case 7:
            s.count(head);
            break;
        case 8:
            int n;
            cout<<"\nFirst we have to create another(2) list \n";
            head1=s.create(head1);
            cout<<"\nHow many nodes you have to insertin 2 list \n";
            cin>>n;
            for(int i=0;i<n;i++)
                s.insert(head1);
            cout<<"\nWe merge list1 and list 2 \n";
            s.merge(head,head1);
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
    public:
    char name[10];
    char DOB[10];
    long telephone;
    int rollno;
};

vector<Student> o1;

void display()
{
    for(auto i1:o1)
    {
        cout<<"\n";
        cout<<"Student Name : "<<i1.name<<endl;
        cout<<"Student DoB : "<<i1.DOB<<endl;
        cout<<"Student Telephone : "<<i1.telephone<<endl;
        cout<<"Stuent Roll Number : "<<i1.rollno<<endl;
    }
}
void insert()
{
    Student i1;
    cout<<"\n";
    cout<<"Enter Student Name : "<<endl;
    cin>>i1.name;
    cout<<"Enter Student DoB : "<<endl;
    cin>>i1.DOB;
    cout<<"Enter Student Telephone : "<<endl;
    cin>>i1.telephone;
    cout<<"Enter Stuent Roll Number : "<<endl;
    cin>>i1.rollno;

    o1.push_back(i1);
}
void search()
{
    int n;
    bool flag=false;
    cout<<"\nEnter Student Roll No to Search : ";
    cin>>n;
    for(auto i1:o1)
    {
        if(i1.rollno==n) flag=true;
    }
    if(flag) cout<<"\nFound";
    else cout<<"\nNot Found";
    cout<<endl;
}
bool compare(Student &i1,Student &i2)
{
    return i1.rollno<i2.rollno;
}

int main()
{
    int ch;
    do
    {
        cout<<"\nMENU";
        cout<<"\n1.Insert";
        cout<<"\n2.Display";
        cout<<"\n3.Search";
        cout<<"\n4.Sort";
        cout<<"\n5.Exit";
        cout<<"\nEnter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            sort(o1.begin(),o1.end(),compare);
            cout<<"\nSorted on Roll Numbers";
            display();
            break;
        case 5:
            exit(0);
        }
    }while(ch!=6);
    return 0;
}
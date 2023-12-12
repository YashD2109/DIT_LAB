#include <iostream>
#include <fstream>
using namespace std;

class Employee
{
    public:
    string name;
    int id;
    double salery;

    public:
    void accept()
    {
        cout<<"\nEnter Name: ";
        cin.ignore();
        getline(cin,name);
        //cin>>name;
        cout<<"\nEnter ID: ";
        cin>>id;
        cout<<"\nEnter Salary: ";
        cin>>salery;
    }
    void display(Employee& e)
    {
        cout<<"\nName is: "<<e.name<<endl;
        cout<<"\nID: "<<e.id<<endl;
        cout<<"\nSalery: "<<e.salery<<endl;
    }
};

int main()
{
    Employee e1;
    fstream f;
    int i,n;
    f.open ("Employee.txt",ios::out);
    cout<<"\nHow many employee info do you wantto store?"<<endl;
    cin>>n;
    cout<<"\nEnter Information of Employee: "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"\nEnter Information of : "<<i<<"\nEmployee";
        e1.accept();
        f.write((char*) & e1,sizeof(e1));
    }
    f.close();

    f.open("Employee.txt",ios::in);
    cout<<"\nInformation of Employees is: "<<endl;
    for(int i=0;i<n;i++)
    {
        f.read((char*)& e1,sizeof(e1));
        e1.display(e1);
    }
    f.close();
    return 0;
}
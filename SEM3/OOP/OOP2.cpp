#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class Db
{
    int roll;
    string name, Class, div, dob, bg, contact, phone, license;

    public:
    static int stdno;

    static void count()
    {
        cout<<"\nNo. of oObject Created: "<<stdno;
    }
    void fin()
    {
        cout<<"In Inline Function!";
    }

//Default Constructor
    Db()
    {
        roll=stdno;
        name="ABCDEF";
        Class="I";
        div="A";
        dob="01-01-2022";
        bg="O+ve";
        contact="Pune";
        phone="1234567890";
        license="ABC102030XYZ";
        stdno++;
    }

//Copy Constructor
    Db(Db *ob)
    {
        roll=ob->roll;
        name=ob->name;
        Class=ob->Class;
        div=ob->div;
        dob=ob->dob;
        bg=ob->bg;
        contact=ob->contact;
        phone=ob->phone;
        license=ob->license;
        stdno++;
    }

    void getdata()
    {
        cout<<"\n\nEnter: Name,RollNo,Class,Division,DoB,Blood Group,Contact,Phone,Licence\n";
        cin>>name>>roll>>Class>>div>>dob>>bg>>contact>>phone>>license;
    }
    friend void display(Db d);
    ~Db()
    {
        cout<<"\n\n"<<this->stdno<<this->name<<"(Object is Destroyed!)";
    }
};

void display(Db d)
{
    cout<<"\n\nName "<<d.name<<"\nRollNo "<<d.roll<<"\nClass "<<d.Class<<"\nDivision "<<d.div<<"\nDoB "<<d.dob
    <<"\nBlood Group "<<d.bg<<"\nContact "<<d.contact<<"\nPhone "<<d.phone<<"\nLicense "<<d.license<<endl;
}

int Db::stdno=0;

int main()
{
    int n,i;
    Db d1,*ptr[5];
    cout<<"Default Values: ";
    display(d1);
    d1.getdata();
    cout<<endl;
    display(d1);

    Db d2(&d1);
    cout<<"\n\nUse of Copy Constructor: ";
    display(d2);

    cout<<"\nHow Many Objects You Want to Create ? : ";
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        ptr[i]=new Db();
        ptr[i]->getdata();
    }

    for(int i=0;i<n;i++) display(*ptr[i]);

    Db::count();
    for(int i=0;i<n;i++) delete(ptr[i]);
    
    cout<<"\nObjects Deleted ! ";

    return 0;
}

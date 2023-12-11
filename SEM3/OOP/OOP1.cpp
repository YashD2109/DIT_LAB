#include <iostream>
using namespace std;
class Complex
{
    public:
    float real,img;
    Complex()//Default Constructor
    {
        real=0;
        img=0;
    }
    Complex operator +(Complex);
    Complex operator *(Complex);
    friend ostream & operator << (ostream &,Complex &);
    friend istream & operator >> (istream &,Complex &);
};

//Overload Operator >>
istream & operator >>(istream &in,Complex &obj)
{
    in>>obj.real;
    in>>obj.img;
    return in;
}

//Overload Operator <<
ostream &operator <<(ostream &out,Complex &obj)
{
    out<<obj.real;
    out<<"+"<<obj.img<<"i";
    return out;
}

//Overrload Operator +
Complex Complex::operator + (Complex obj)
{
    Complex temp;
    temp.real=real+obj.real;
    temp.img=img+obj.img;
    return temp;
}

//Overload Operator *
Complex Complex::operator * (Complex obj)
{
    Complex temp;
    temp.real=real*obj.real-img*obj.img;
    temp.img=real*obj.img+img*obj.real;
    return (temp);
}

int main()
{
    Complex a,b,c,d;
    cout<<"1st Complex Number - Enter Real and Imaginary\n";
    cin>>a;
    cout<<"2nd Complex Number - Enter Real and Imaginary\n";
    cin>>b;
    cout<<"Arithmatic Operations: ";
    c=a+b;
    cout<<"\nAdditon = "<<c;
    d=a*b;
    cout<<"\nMultplication = "<<d<<endl;
    return 0;
}
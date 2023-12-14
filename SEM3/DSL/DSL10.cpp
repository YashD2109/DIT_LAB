#include <iostream>
using namespace std;
#define size 30

class stackexp
{
public:
    int top;
    char stk[size];
    stackexp()
    {
        top=-1;
    }
    void push(char ch)
    {
        top++;
        stk[top]=ch;
    }
    char pop()
    {
        char s;
        s=stk[top];
        top--;
        return s;
    }
    bool isFull()
    {
        if(top==size) return true;
        else return false;
    }
    bool isEmpty()
    {
        if(top==-1) return true;
        else return false;
    }
};

int main()
{
    stackexp s1;
    string str;
    char ch,top,temp;

    cout<<"Enter the statement to check whether it is well parenthisis or not : \n";
    cin>>str;
    int i=0;
    while(str[i]!='\0')
    {
        ch=str[i];
        switch(ch)
        {
        case '(': 
            s1.push(ch);break;
        case '[': 
            s1.push(ch);break;
        case '{': 
            s1.push(ch);break;
        case ')':
            if(s1.isEmpty()) s1.push(ch);
            else 
            {
                temp=s1.pop();
                if(temp!='(') 
                {
                    s1.push(temp);
                    s1.push(ch);
                }
            }
            break;
        case ']':
            if(s1.isEmpty()) s1.push(ch);
            else 
            {
                temp=s1.pop();
                if(temp!='[') 
                {
                    s1.push(temp);
                    s1.push(ch);
                }
            }
            break;
        case '}':
            if(s1.isEmpty()) s1.push(ch);
            else 
            {
                temp=s1.pop();
                if(temp!='{') 
                {
                    s1.push(temp);
                    s1.push(ch);
                }
            }
            break;           
        }
        i++;
    }
    if(s1.isEmpty()) cout<<"Well Parenthisis \n";
    else cout<<"Invalid Expression \n";
}
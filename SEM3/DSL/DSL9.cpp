#include <iostream>
#include <stack>
#include <cctype>//for std::alnum
#include <string>

using namespace std;

stack<char> charStack;
void convert(string str)
{
    for(auto i:str) 
    {
        if(isalnum(i)) charStack.push(i);
    }
}
void printReverse(string str)
{
    convert(str);
    cout<<"Reverse String \n";
    while(!charStack.empty()) 
    {
        cout<<charStack.top();
        charStack.pop();
    }
    cout<<endl;
}

bool isPalindrome(string str)
{
    convert(str);
    for(auto i:str)
    {
        if(isalnum(i))
        {
            if(i!=charStack.top()) return false;
        }
        charStack.pop();
    }
    return true;
}
int main()
{
    
    string str;
    cout<<"Enter the String ";
    getline(cin,str);

    cout<<"Given String is: \n"<<str<<endl;
    printReverse(str);

    if(isPalindrome(str)) cout<<"Given String is Palindrome \n";
    else cout<<"Given String is Not Palindrome \n";
}

#include <iostream>
using namespace std;

template <class T>
void selection_sort()
{
    T a[10];
    T temp;
    for(int i=0;i<10;i++)
    {
        cout<<"a["<<i<<"] = ";
        cin>>a[i];
    }
    for(int i=0;i<10;i++)
    {
        for(int j=i;j<10;j++)
        {
            if(a[i]>a[j]) 
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<"\nSorted Array: "<<endl;
    for(auto i:a) cout<<i<<" ";
    cout<<endl;
}

int main()
{
    cout<<"\nEnter Numbers to be Sorted: "<<endl;
    cout<<"\nInteger Sorting...."<<endl;
    selection_sort<int>();

    cout<<"\nFloating sorting...."<<endl;
    selection_sort<float>();
}
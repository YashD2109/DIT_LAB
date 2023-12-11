#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string,int> populationMap;
    populationMap.insert({"MH",112});
    populationMap.insert({"UP",199});    
    populationMap.insert({"MP",726});
    populationMap.insert({"AP",845});

    cout<<"\n\nSize of PopulationMap : "<<populationMap.size()<<endl;
    for(auto i:populationMap) cout<<i.first<<" : "<<i.second<<" million\n";

    string state;
    cout<<"\nEnter the State : ";
    cin>>state;

    auto iter=populationMap.find(state);
    if((*iter).second!=0) cout<<state<<"'s Population is "<<(*iter).second<<" million\n";
    else cout<<"Key is not in PopulationMap\n";
}
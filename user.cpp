#include<iostream>
#include<set>
#include<map>
using namespace std;
class person_compare{
    public:
    bool operator()(pair<string,int> p1, pair <string,int> p2){
        return p1.second < p2.second;
    }
};
int main(){
    
    /*
            100
        A ------- B
         \       /
     50   \     / 50
           \  /
             C
    A owes B 100
    B owes C 50
    C owes A 50
    */
    
    int no_of_transactions,friends;
    cout<<"Enter the total no of transaction and number of friends :-  ";
    cin>>no_of_transactions>>friends;
    string x,y;
    int amount;
    map<string,int>net;
    while(no_of_transactions--){
        cout<<"Select the debiter and crediter and the amount. ";
        cin>>x>>y>>amount;
        //count() is a built-in function in C++ STL which returns 1 
        //if the element with key K is present in the map container. 
        //It returns 0 if the element with key K is not present in the container.
        if(net.count(x)==0){
            net[x]=0; //zero initialisation
        }
        if(net.count(y)==0){
            net[y]=0; //zero initialisation
        }
        net[x]-=amount;
        net[y]+=amount;
    }
    
    multiset<pair<string,int>,person_compare> m;
    for(auto p:net){
        string person = p.first;
        int amount = p.second;
        
        if(net[person]!=0){
            m.insert(make_pair(person,amount));
        }
    }
    int count=0;
    //Greedy Approach
    //Person with highest debt will pay the credit.
    //Pop out two person from left and right.
    while(!m.empty()){
            auto low=m.begin();
            auto high=prev(m.end());// Same as array end isnt the last one.But here we cant use -1 so we use prev.
        //We will try to settle transaction. Low and high are pointers . SO we need to dereference them
        int debit = low->second;
        string debit_person= low->first;
        int credit = high->second;
        string credit_person = high->first;
        //Erase the element from multiset
        m.erase(low);
        m.erase(high);
        
        //Settlement
        int settlement_amount = min(-debit,credit);
        
        //Settlement amount from donor to acceptor
        //It will be sureshot one of them will be zero.
        debit +=settlement_amount;
        credit -=settlement_amount;
        cout<<debit_person<<" will pay "<<settlement_amount<<" to "<<credit_person<<endl;
        if(debit!=0){
            m.insert(make_pair(debit_person,debit));
        }
        if(credit!=0){
            m.insert(make_pair(credit_person,credit));
        }
        count++;
    }
    cout<<count<<endl;
}
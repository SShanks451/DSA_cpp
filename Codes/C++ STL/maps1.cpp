#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,string> m;
    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";
    m[6] = "a";
    m.insert({4,"afg"});

    // Printing map
    map<int,string> :: iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }

    // Printing map(method-2)
    for(auto &pr : m){
        cout << pr.first << " " << pr.second << endl;
    }

    //size of map
    cout << m.size() << endl;

    // finding element in map
    auto itr = m.find(3);
    if(itr==m.end()){
        cout << "NOT FOUND" << endl;
    }else{
        cout << (*itr).first << " " << (*itr).second << endl;
    }

    // to erase an element in map
    auto itr1 = m.find(1);
    m.erase(itr1);
    for(auto &pr : m){
        cout << pr.first << " " << pr.second << endl;
    }


    return 0;
}
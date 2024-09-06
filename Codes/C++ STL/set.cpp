#include<bits/stdc++.h>
using namespace std;

int main(){
    set<string> s;
    s.insert("abc"); // o(logn)
    s.insert("zsdf");
    s.insert("bcd");

    // printing set
    for(string value : s){
        cout << value << endl;
    }

    // finding element in set
    auto it = s.find("abc");  // O(logn)
    if(it != s.end()){
        cout << (*it) << endl;
    }

    // deleting element in set
    if(it != s.end()){
        s.erase(it);
    }
    for(string value : s){
        cout << value << endl;
    }
    // s.erase() can take iterator as well as value;
    s.erase("bcd");
    for(string value : s){
        cout << value << endl;
    }



    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void print(multiset<string> &s){
    for(string value : s){
        cout << value << endl;
    }
}
 
int main(){
    multiset<string> s;
    s.insert("abc"); //O(log n)
    s.insert("zsdf");
    s.insert("bcd");
    s.insert("abc");
    print(s);

    auto it = s.find("abc");
    if(it != s.end()){
        s.erase(it);
    }

    return 0;
}

// in multiset we can keep repeated elements
#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,string> m;
    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";
    m[6] = "a";
    m[5] = "cde";

    for(auto &pr : m){
        cout << pr.first << " " << pr.second << endl;
    }

    // maps use TREE for inbuilt implementation whereas unordered maps use HASHTABLE for inbuilt implementation
    // time complexity for operations in case of unordered maps is O(1)
    // Unordered sets and maps can't take complex data structures like pair,sets,maps. 

    return 0;
}
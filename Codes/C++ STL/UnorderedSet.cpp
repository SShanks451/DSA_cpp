#include<bits/stdc++.h>
using namespace std;
 
int main(){
    unordered_set<string> s;
    s.insert("abc"); // O(1)
    s.insert("zsdf");
    s.insert("bcd");
    s.insert("abc");

    // If order doesn't matter use unordered set.
    // Unordered sets and maps can't take complex data structures like pair,sets,maps. 

    return 0;
}
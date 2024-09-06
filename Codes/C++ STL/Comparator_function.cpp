#include <bits/stdc++.h>
using namespace std;

// for normal swapping
bool should_i_swap(int a, int b){
    if(a>b) return true;
    return false;
}

// In case of pair (if we want to sort "first" in ascending and corresponding "second" in descending)
bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first!=b.first){
        return a.first<b.first;
    }else{
        return a.second>b.second;
    }
}



int main(){
    


    return 0;
}
// question link:- https://www.geeksforgeeks.org/the-stock-span-problem/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(arr)/sizeof(arr[0]);

    stack<int> s;
    vector<int> v;

    for(int i=0; i<n; i++){
        if(s.size()==0){
            v.push_back(-1);
        }else{
            while(s.size()!=0 && arr[s.top()]<=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }else{
                v.push_back(s.top());
            }
        }
        s.push(i);
    }

    for(int i=0; i<n; i++){
        v[i] = i - v[i];
    }
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }

    return 0;
}
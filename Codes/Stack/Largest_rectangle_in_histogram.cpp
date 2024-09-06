// question link :- https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i=0; i<n; i++){
        cin >> heights[i];
    }
    stack<int> s;
    vector<int> nsl;
    vector<int> nsr;
    for(int i=0; i<n; i++){
        while(s.size()!=0 && heights[s.top()]>=heights[i]){
            s.pop();
        }
        if(s.size()==0){
            nsl.push_back(-1);
        }else{
            nsl.push_back(s.top());
        }
        s.push(i);
    }
    while(s.size()!=0) s.pop();
    for(int i=n-1; i>=0; i--){
        while(s.size()!=0 && heights[s.top()]>=heights[i]){
            s.pop();
        }
        if(s.size()==0){
            nsr.push_back(n);
        }else{
            nsr.push_back(s.top());
        }
        s.push(i);
    }
    reverse(nsr.begin(), nsr.end());
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        int calc = (nsr[i]-nsl[i]-1)*heights[i];
        ans = max(ans, calc);
    }
    cout << ans;

    return 0;
}
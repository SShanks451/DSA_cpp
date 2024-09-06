// question link :- https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;

bool checkPossible(string &s1, string &s2){
    if(s2.size()+1 != s1.size()){
        return false;
    }
    int i=0;
    int j=0;
    while(i < s1.size()){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }else{
            i++;
        }   
    }
    if(i==s1.size() && j==s2.size()){
        return true;
    }
    return false;
}

bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}


int main(){

    int n;
    cin >> n;
    vector<string> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), comp);

    vector<int> dp(n,1);

    int maxm = dp[0];
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(checkPossible(vec[i],vec[j]) && 1+dp[j]>dp[i]){
                dp[i] = 1+dp[j];
            }
        }
        maxm = max(maxm, dp[i]);
    }

    cout << maxm;

    return 0;
}
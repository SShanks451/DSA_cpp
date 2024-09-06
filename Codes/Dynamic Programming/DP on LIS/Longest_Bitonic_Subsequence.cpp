// question link :- https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


// dp1 => LIS from start index
// dp2 => LIS from end index

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    vector<int> dp1(n,1);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(vec[j]<vec[i] && 1+dp1[j]>dp1[i]){
                dp1[i] = 1+dp1[j];
            }
        }
    }

    vector<int> dp2(n,1);
    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(vec[j]<vec[i] && 1+dp2[j]>dp2[i]){
                dp2[i] = 1+dp2[j];
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp1[i]+dp2[i]-1);
    }
    cout<<ans;

    return 0;
}
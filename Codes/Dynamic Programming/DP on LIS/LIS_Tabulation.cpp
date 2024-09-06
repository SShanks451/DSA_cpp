
// state :-
// dp[i] = signifies the length of LIS that ends at index i

// time complexity :- O(N*N)
// space complexity :- O(N)

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    vector<int> dp(n, 1);
    int ans = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(vec[i] > vec[j]){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}
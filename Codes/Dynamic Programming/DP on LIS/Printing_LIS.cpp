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
    vector<int> hash(n);

    int maxi = 1;
    int lastIndex = 0; 
    for(int i=0; i<n; i++){
        hash[i] = i;
        for(int j=0; j<i; j++){
            if((vec[i] > vec[j]) && (1+dp[j] > dp[i])){
                dp[i] = 1+dp[j];
                hash[i] = j;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> ans;
    ans.push_back(vec[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        ans.push_back(vec[lastIndex]);
    }

    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}
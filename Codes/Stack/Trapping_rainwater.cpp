// question link :- https://www.geeksforgeeks.org/trapping-rain-water/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    const int n = sizeof(height)/sizeof(height[0]);

    int maxl[n];
    int maxr[n];
    maxl[0] = height[0];
    for(int i=1; i<n; i++){
        maxl[i] = max(height[i], maxl[i-1]);
    }
    maxr[n-1] = height[n-1];
    for(int i=n-2; i>=0; i--){
        maxr[i] = max(height[i], maxr[i+1]);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int ht = min(maxl[i], maxr[i]);
        ans += (ht-height[i]);
    }
    cout<<ans;

    return 0;
}
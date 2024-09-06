// question link :- https://www.spoj.com/problems/EKO/

#include<bits/stdc++.h>
using namespace std;
const int N = 1E6+10;
int n;
long long m;
long long trees[N];

bool isWoodSufficient(int h){
    long long wood = 0;
    for(int i=0; i<n; i++){
        if(trees[i] >= h){
            wood += (trees[i]-h);
        }
    }

    return wood >= m;
}

int main(){

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> trees[i];
    }
    long long lo = 0, hi = 1e9, mid, ans;
    while(hi >= lo){
        mid = (lo+((hi-lo)/2));
        if(isWoodSufficient(mid)){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }

    cout << mid;

    return 0;
}
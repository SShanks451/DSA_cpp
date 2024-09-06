// question link :- https://www.spoj.com/problems/AGGRCOW/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,cows;
long long positions[N];

bool canPlaceCows(int minDistance){
    int cows_cnt = cows;
    int lastPos = -1;
    for(int i=0; i<n; i++){
        if((positions[i] - lastPos >= minDistance) || (lastPos == -1)){
            cows_cnt--;
            lastPos = positions[i];
        }
        if(cows_cnt == 0){
            break;
        }
    }
    return (cows_cnt == 0);
}

int main(){

    int t;
    cin >> t;
    while(t--){
        cin >> n >> cows;
        for(int i=0; i<n; i++){
            cin >> positions[i];
        }
        sort(positions, positions+n);
        long long lo = 0, hi = 1e9, mid, ans;
        while(hi >= lo){
            mid = (lo+((hi-lo)/2));
            if(canPlaceCows(mid)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        cout << ans << endl;
    }

    

    return 0;
}
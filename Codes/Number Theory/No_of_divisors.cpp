#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long 
using namespace std;
const ll MAX = 1e6+1;
ll spf[MAX];

int main(){
    fastio;

    for(ll i=0; i<MAX; i++){
        spf[i] = i;
    }
    for(ll i=2; i*i<MAX; i++){
        if(spf[i]==i){
        for(ll j=i*i; j<MAX; j+=i){
            if(spf[j]==j){
                spf[j] = i;
            }
        }
        }
    }   

    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ll ans = 1;
        while(n>1){
            ll smallest = spf[n];
            ll k = 0;
            while(n%smallest == 0){
                k+=1;
                n = n/smallest;
            }
            ans = ans*(k+1);
            
        }
        cout << ans << endl;
    }


    return 0;
}
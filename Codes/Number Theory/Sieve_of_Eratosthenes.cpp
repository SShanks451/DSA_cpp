#include<bits/stdc++.h>
using namespace std;

bool isPrime[10000000];

int main(){
    int q;
    cin >> q;
    for(int i=0; i<=1e7; i++){
        isPrime[i] = 1;
    }
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(int i=2; i*i<=1e7; i++){
        if(isPrime[i]==1){
            for(int j=i*i; j<=1e7; j+=i){
                isPrime[j] = 0;
            }
        }
    }
    // Time complexity is O(Nlog(log(N)))

    while(q--){
        int x;
        cin >> x;
        if(isPrime[x]){
            cout << x << " is PRIME" << endl;
        }else{
            cout << x << " is NOT PRIME" << endl;
        }
    }    

    return 0;
}
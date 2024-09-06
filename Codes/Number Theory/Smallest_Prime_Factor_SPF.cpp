#include<bits/stdc++.h>
using namespace std;
int spf[1000001];

int main(){
    int q;
    cin >> q;
    
    for(int i=0; i<=1e6; i++){
        spf[i] = i;
    }
    for(int i=2; i*i<=1e6; i++){
        if(spf[i]==i){
            for(int j=i*i; j<=1e6; j+=i){
                if(spf[j]==j){
                    spf[j] = i;
                }
            }
        }
    }
    while(q--){
        int x; 
        cin >> x;
        cout << spf[x] << endl;
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int calculate(int x, int n, int m){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return calculate(((x%m)*(x%m))%m,n/2,m);
    }
    return (x%m)*calculate(((x%m)*(x%m))%m,(n-1)/2,m);
}





int main(){
    int x,n,m;
    cin >> x >> n >> m;
    cout << calculate(x,n,m);


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int iter(int x, int n){
    int ans = 1;
    while(n!=0){
        if(n%2 == 1){
            ans *= x;
        }
        x *= x;
        n /= 2;

    }
    return ans;

}

int main(){
    int x,n;
    cin >> x >> n;
    cout << iter(x,n);

    return 0;
}

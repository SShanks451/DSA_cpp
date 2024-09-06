// finding square root of a number upto some decimal places

#include<bits/stdc++.h>
using namespace std;

int main() {

    double n;
    cin>>n;
    double lo = 1;
    double hi = n;
    double eps = 1e-7;
    double ans;
    while(hi-lo>eps){
        double mid = (lo+hi)/2.00;
        if(mid*mid>n){
            hi = mid;
        }else{
            ans = mid;
            lo = mid;
        }
    }
    cout<<ans;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int c = __gcd(a,b); // Inbuilt function for gcd
    int lcm = (a/c) * b;
    cout << lcm;


    return 0;
}
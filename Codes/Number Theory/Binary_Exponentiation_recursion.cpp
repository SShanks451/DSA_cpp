#include<bits/stdc++.h>
using namespace std;

int BinaryExp(int a, int b){
    if(b==0) return 1;
    if(b%2 == 1) return a*BinaryExp(a*a, b/2);
    return BinaryExp(a*a, b/2);


}

int main(){
    int x,n;
    cin >> x >> n;
    cout << BinaryExp(x,n);

    return 0;
}
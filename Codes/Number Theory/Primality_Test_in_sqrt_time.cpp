#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int divisors = 0;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            int first_divisor = i;
            int second_divisor = n/i;
            if(first_divisor != second_divisor){
                divisors += 2;
            }else{
                divisors++;
            }
        }
    }
    if(divisors == 2){
        cout << "PRIME";
    }else{
        cout << "NOT PRIME";
    }

    // Time complexity is O(sqrt(n))

    return 0;
}
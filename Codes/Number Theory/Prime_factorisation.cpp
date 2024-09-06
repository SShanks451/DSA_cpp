#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<pair<int, int>> vec;

    for(int i=2; i*i<=n; i++){
        int cnt = 0;
        while(n % i == 0){
            n /= i;
            cnt++;
        }
        vec.push_back({i, cnt});
    }
    if(n != 1){
        vec.push_back({n,1});
    }

    for(int i=0; i<vec.size(); i++){
        cout << vec[i].first << " " << vec[i].second << endl;
    }

    return 0;
}
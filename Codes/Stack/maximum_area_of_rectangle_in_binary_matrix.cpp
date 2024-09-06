// question link :- https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/

#include <bits/stdc++.h>
using namespace std;

int MAH(vector<int> &vec){
    int n = vec.size();
    stack<int> s;
    vector<int> nsl;
    vector<int> nsr;

    for(int i=0; i<n; i++){
        while(s.size()!=0 && vec[s.top()]>=vec[i]){
            s.pop();
        }
        if(s.size()==0){
            nsl.push_back(-1);
        }else{
            nsl.push_back(s.top());
        }
        s.push(i);
    }
    while(s.size()!=0) s.pop();
    for(int i=n-1; i>=0; i--){
        while(s.size()!=0 && vec[s.top()]>=vec[i]){
            s.pop();
        }
        if(s.size()==0){
            nsr.push_back(n);
        }else{
            nsr.push_back(s.top());
        }
        s.push(i);
    }
    reverse(nsr.begin(), nsr.end());
    int calc = INT_MIN;
    for(int i=0; i<n; i++){
        calc = max(calc, (nsr[i]-nsl[i]-1)*vec[i]);
    }
    return calc;

}

int main(){

    int n = 4;
    int m = 4;
    int M[4][4] = {{0, 1, 1, 0},
                    {1, 1, 1, 1},
                    {1, 1, 1, 1},
                    {1, 1, 0, 0}};
    
    vector<int> vec;
    for(int j=0; j<m; j++){
        vec.push_back(M[0][j]);
    }

    int ans = MAH(vec);

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(M[i][j] == 0){
                vec[j] = 0;
            }else{
                vec[j]++;
            }
        }
        ans = max(ans, MAH(vec));
    }
    cout << ans << endl;


    return 0;
}
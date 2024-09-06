// question link :- https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


// This method only gives length of LIS
// time complexity :- O(N*logN)


#include <bits/stdc++.h>
using namespace std;


int lisLength(vector<int> &vec, int n){
    vector<int> temp;
    temp.push_back(vec[0]);
    for(int i=1; i<n; i++){
        if(vec[i] > temp.back()){
            temp.push_back(vec[i]);
        }else{
            int indx = lower_bound(temp.begin(), temp.end(), vec[i]) - temp.begin();
            temp[indx] = vec[i];
        }
    }
    return temp.size();
}


int main(){

    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    cout << lisLength(vec, n);

    return 0;
}
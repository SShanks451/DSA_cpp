#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec = {2,3,5,6,7};

    // using auto keyword
    for(auto it=vec.begin(); it!=vec.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;

    // using auto and range based loops
    vector<pair<int,int>> v_p = {{1,2},{2,3}};
    for(auto &value : v_p){
        cout << value.first << " " << value.second << endl; 
    }
    cout << endl;

    return 0;
}
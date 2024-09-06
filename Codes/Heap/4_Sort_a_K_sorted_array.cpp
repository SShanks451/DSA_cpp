// question link :- https://www.geeksforgeeks.org/nearly-sorted-algorithm/

#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> vec = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    vector<int> ans;

    priority_queue<int, vector<int>, greater<int>> minH;

    for(int i=0; i<vec.size(); i++) {
        minH.push(vec[i]);
        if(minH.size() > k) {
            ans.push_back(minH.top());
            minH.pop();
        }
    }

    while(!minH.empty()){
        ans.push_back(minH.top());
        minH.pop();
    }

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
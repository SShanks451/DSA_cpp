#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {7,10,4,3,20,15};
    int k = 3;

    priority_queue<int, vector<int>, greater<int>> minH;

    for(int i=0; i<arr.size(); i++) {
        minH.push(arr[i]);
        if(minH.size() > k) {
            minH.pop();
        }
    }

    while(!minH.empty()) {
        cout << minH.top() << " ";
        minH.pop(); 
    }

    return 0;
}
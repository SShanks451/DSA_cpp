#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;

    priority_queue<int> maxH;

    for(int i=0; i<nums.size(); i++) {
        maxH.push(nums[i]);
        if(maxH.size() > k) {
            maxH.pop();
        }
    }

    cout << maxH.top();

    return 0;
}
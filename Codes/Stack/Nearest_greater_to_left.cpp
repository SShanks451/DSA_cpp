#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> vec = {1,3,0,0,1,2,4};
    int n = vec.size();

    stack<int> st;
    vector<int> ans;

    for(int i=0; i<n; i++) {
        if(st.empty()) {
            ans.push_back(-1);
        }else{  
            while(!st.empty() && st.top() <= vec[i]) {
                st.pop();
            }
            if(!st.empty()) {
                ans.push_back(st.top());
            }else{
                ans.push_back(-1);
            }
        }
        st.push(vec[i]);
    }

    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
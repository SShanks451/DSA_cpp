// Time Complexity = O(NlogN)
// Space complexity = O(1)

#include <bits/stdc++.h>
using namespace std;


int place_pivot(int low, int high, vector<int> &vec) {
    int pivot_elem = vec[low];
    int i = low;
    int j = high;
    while(i < j) {
        while(vec[i] <= pivot_elem && i < high) {
            i++;
        }
        while(vec[j] > pivot_elem && j > low) {
            j--;
        }
        if(i < j) {
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[low], vec[j]);
    return j;
}


void quick_sort(int low, int high, vector<int> &vec) {
    if(low < high) {
        int pivot = place_pivot(low, high, vec);
        quick_sort(low, pivot-1, vec);
        quick_sort(pivot+1, high, vec);
    }
}


int main() {

    vector<int> vec = {4,6,2,5,7,9,1,9};
    int n = vec.size();

    quick_sort(0, n-1, vec);

    for(int i=0; i<n; i++) {
        cout << vec[i] << " ";
    }

    return 0;
}
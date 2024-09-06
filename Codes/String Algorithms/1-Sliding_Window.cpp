// question => Given text T and pattern P, find whether P exists in T or not. In case it exists, print all the occurences of pattern in the text.


#include <bits/stdc++.h>
using namespace std;

string T, P;
int LP, LT;

// LP => length pf pattern 
// LT => length of text

bool match(int L, int R) {
    for(int i=0; i<LP; i++){
        if(T[L+i] != P[i]) return false;

        return true;
    }
}

int main(){

    int t;
    cin >> t;

    cin.ignore();

    while(t--){
        getline(cin, T);
        getline(cin, P);
        LP = P.size();
        LT = T.size();

        for(int L=0, R=LP-1; R<LT; L++, R++) {
            if(match(L, R)) {
                cout << L << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}
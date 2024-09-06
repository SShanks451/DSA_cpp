// question link :- https://leetcode.com/problems/n-queens/



#include <bits/stdc++.h>
using namespace std;


bool check(int col, int row, vector<string> &board, int n){
    int nRow = row;
    int nCol = col;
    while(nRow>=0 && nCol>=0){
        if(board[nRow][nCol] == 'Q'){
            return false;
        }
        nRow--;
        nCol--;
    }
    nRow = row;
    nCol = col;
    while(nCol>=0){
        if(board[nRow][nCol] == 'Q'){
            return false;
        }
        nCol--;
    }
    nRow = row;
    nCol = col;
    while(nRow<n && nCol>=0){
        if(board[nRow][nCol] == 'Q'){
            return false;
        }
        nRow++;
        nCol--;
    }
    return true;

}

void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row=0; row<n; row++){
        if(check(col, row, board, n)){
            board[row][col] = 'Q';
            solve(col+1, ans, board, n);
            board[row][col] = '.';
        }
        
    }
}

int main() {

    int n;
    cin >> n;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s = {};
    for(int i=0; i<n; i++){
        s.push_back('.');
    }
    for(int i=0; i<n; i++){
        board[i] = s;
    }
    solve(0, ans, board, n);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }


    return 0;
}
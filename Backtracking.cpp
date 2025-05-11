#include<bits/stdc++.h>
using namespace std;

int placed[8];
string board[8];

int check(int row, int col){
    //can't place in this row, col if
    //placed[row] != -1 (already placed in this row)
    //col in placed (already placed in this col)
    //if abs(row - i) = abs(col - placed[row]).  for i from 0 to row - 1
    if(placed[row] != -1) return 0;
    for(auto v: placed){
        if (v == col) return 0;
    }
    for(int i = 0; i < row; i++){
        if(abs(row - i) == abs(col - placed[i])) return 0;
    }
    if(board[row][col] == '*') return 0;
    return 1;

}

int rec(int row){
    //returns the number of ways to fill row, row + 1, ..., n - 1
    //base case
    if(row == 8){
        return 1;
    }
    //compute
    int ans = 0;
    for(int col = 0; col < 8; col++){
        //check if you can place it in this col, given the row
        if(check(row, col)){
            //place
            placed[row] = col;
            //move
            ans += rec(row + 1);
            //unplace
            placed[row] = -1;
        }
    }
    return ans;
}

void solve(){
    for(int i = 0; i < 8; i++){
        cin >> board[i];
    }
    for(int i = 0; i < 8; i++){
        placed[i] = -1; // initially everything unplaced
    }
    cout << rec(0) << '\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}

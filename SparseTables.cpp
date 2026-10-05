#include<bits/stdc++.h>
using namespace std;
//------------------SPARSE TABLES---------------------
int n, q;
int a[100100], b[100100];
int mxm[100100][30];
const int LOG = 30;
map<int, int> mp;
void solve(){
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = 0;
    }
    for(int i = 0;i < n; i++) {
        cin >> b[i];
        mp[b[i]] = 1;
    }
    
    //Build 
    for(int i = 0; i < n; i++) mxm[i][0] = max(a[i], b[i]);
    for(int j = 1; j < LOG; j++){
        for(int i = 0; i + (1<<(j - 1)) < n; i++){
            mxm[i][j] = max(mxm[i][j - 1], mxm[i + (1<<(j-1))][j - 1]);
        }
    }
    
    //Query
    while(q--){
        int l, r;
        int ans = -1e9;
        cin >> l >> r;
        l--; r--;
        int ln = r - l + 1;
        for(int i = LOG - 1; i >= 0; i--){
            if(ln & (1<<i)){
                ans = max(ans, mxm[l][i]);
                l += (1<<i);
            }
        }
        if(mp[ans] == 1) {
            cout << "Bob\n";
        }
        else{
            cout << "Alice\n";
        }
    }
}

signed main(){
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}

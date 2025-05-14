#include<bits/stdc++.h>
using namespace std;
int n, q, k;
const int N = 1000005;
int p[N];
void solve(){
    cin >> n >> k >> q;
    for(int i = 0; i < N; i++) p[i] = 0;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        p[l]++; 
        p[r + 1]--;
    }
    // build prefix sum for partial sum array p
    p[0] = 0;
    for(int i = 1; i < N; i++){
        p[i] = p[i] + p[i - 1];
    }
    // p contains the array where ith number is liked by p[i] students
    for(int i = 1; i < N; i++){
        if (p[i] >= k) p[i] = 1;
        else p[i] = 0;
    }
    // p is array where ith indx indicates whether ith no. is liked by k or more students
    for(int i = 1; i < N; i++){
        p[i] = p[i] + p[i - 1];
    }
    // p is now fully processed
    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = p[r] - p[l - 1];
        cout << ans << '\n';
    }

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

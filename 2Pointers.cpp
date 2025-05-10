#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[100100];

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    int head = -1, tail = 0;
    int ans = 0;
    int nz = 0;
    while(tail < n){
        //eat (next) as many as you can
        while(head < n - 1 && (a[head + 1] == 1 || (a[head + 1] == 0 && nz < k))){
            head++;
            //if ds has to be updated, update it
            if(a[head] == 0) nz++;
        }
        //update the ans
        ans = max(ans, head - tail + 1);

        //move start 1 step ahead
        if(tail > head){
            tail++;
            head = tail - 1;
        }
        else{
            //pre-modify the ds
            if(a[tail] == 0) nz--;
            tail++;
        }
    }
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
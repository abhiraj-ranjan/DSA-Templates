#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
vector<int> a, b;

int check(int x){
    // number of elements <= x is >= k
    int num = 0; //num of elements <= x
    for(int i = 0; i < n; i++){
        int targ = x - a[i];
        auto it = upper_bound(b.begin(), b.end(), targ);
        num += it - b.begin();
    }
    if(num >= k) return 1;
    return 0;
}


void solve(){
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    if (n > m) {
        swap(n, m);
        swap(a, b);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int lo = a[0] + b[0];                 //loose bound
    int hi = a[n - 1] + b[m - 1];               //loose bound
    int ans = 0;                //does not matter here
    
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
            ans = mid;
        }
        else lo = mid + 1;
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
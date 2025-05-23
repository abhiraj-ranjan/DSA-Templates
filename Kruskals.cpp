#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define int long long
int n, m;
int par[100100], r[100100];
pair<int, pair<int, int>> e[200100];
int set_size;

int find(int x){
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y){
    x = find(x); y = find(y);
    if(x==y) return;        // both part of same component
    if(r[x] < r[y]){
        //merge x into y
        r[y] += r[x];
        par[x] = y;
    }
    else{
        r[x] += r[y];
        par[y] = x;
    }
    set_size -= 1;    
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = MP(c, MP(a, b));
    }
    for(int i = 1; i <= n; i++){
        r[i] = 1;
        par[i] = i;
    }
    set_size = n;
    sort(e, e + m);
    int ans = 0;
    for(int i = 0; i < m; i++){
        int a = e[i].second.first, b = e[i].second.second, c = e[i].first;
        if(find(a) == find(b)) continue; // cant merge
        merge(a, b);
        ans += c;
    }
    if(set_size == 1){
        //fully connected
        cout << ans << '\n';
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
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

/*
This is implementation of Kruskals, using UnionFind, Kruskals is a greedy algo which takes in cheapest edge that would help in building MST, every edge should be cheapest available, give that it joins 2 disconnected components
*/
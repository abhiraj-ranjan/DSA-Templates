#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
vector<int>sol;
int indeg[200100];

void solve(){
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 1; i <= n; i++){
        indeg[i] = 0;
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }
    priority_queue<int> pq;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0) pq.push(-i);
    }
    while(!pq.empty()){
        int x = -pq.top();
        pq.pop();
        sol.push_back(x);
        for(auto v: g[x]){
            indeg[v]--;
            if(indeg[v] == 0){
                pq.push(-v);
            }
        }
    }
    if(sol.size() == n){
        for(auto v: sol){
            cout << v << ' ';
        }
    }
    else{
        cout << -1;
    }
    cout << '\n';


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
using pq for lexicographic ordering, can also find a topological ordering using DFS, by adding the node to topo/sol vector during post-visit, since then no remaining node will be its descendant.
*/
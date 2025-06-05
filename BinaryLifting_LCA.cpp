#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int par[100100][20];//stores the 2^i distant neighbours from each node (assuming 2^20 as max)
int dep[100100]; //stores the depth of each node from a particular/given root

void build(int node, int prev, int d) {
	//builds the whole binary uplifting
	dep[node] = d;
	par[node][0] = prev;
	for(int i = 1; i < 20; i++) {
		//assuming top to bottom, all the above nodes' pars are calculated already
		par[node][i] = par[par[node][i - 1]][i - 1];
	}
	//now done with the current node
	for(auto v: g[node]) {
		if(v == prev) continue;
		build(v, node, d + 1);
	}
}


int lca(int u, int v) {
	if(dep[u] < dep[v]) {
		swap(u, v);
	}
	//jump u to match the same depth as v
	for(int i = 19; i >= 0; i--) {
		if((dep[u]-dep[v])&(1<<i)) {
			//then jump this distance
			u = par[u][i];
		}
	}
	if(u==v) return u;  //IMPORTANT
	//jump both simultaneously, only if after jumping, you dont land at common node (avoid chance of missing LCA)
	for(int i = 19; i >= 0; i--) {
		if(par[u][i]!=par[v][i]) {
			//can jump
			u = par[u][i];
			v = par[v][i];
		}
	}
	//now the LCA is just one above u (that is prev of u(or v))
	return par[u][0];

}





void solve() {
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--) {
		for(int i = 0; i <= n; i++) {
			a[i] = indp[i] = subSum[i] = outdp[i] = 0;
		}
		g.clear();
		solve();
	}
}
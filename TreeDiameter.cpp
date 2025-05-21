#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> g;
int n;
int dis[200100];
//visited array is not required for trees, since only one path b/w any nodes pair
void dfs(int node, int p, int d) {
	dis[node] = d;
	for(auto v: g[node]) {
		if(v == p) continue;
		dfs(v, node, d + 1);
	}
}

void solve() {
	cin >> n;
	g.resize(n + 1);
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 1; i <= n; i++) {
		dis[i] = -1;

	}
	dfs(1, 0, 0);
	int mxm = -1;
	int idx = -1;
	for(int i = 1; i <= n; i++) {
		mxm = max(mxm, dis[i]);
		if(mxm == dis[i]) idx = i;
	}
	for(int i = 1; i <= n; i++) {
		dis[i] = -1;

	}
	dfs(idx, 0, 0);
	mxm = -1;
	idx = -1;
	for(int i = 1; i <= n; i++) {
		mxm = max(mxm, dis[i]);
		if(mxm == dis[i]) idx = i;
	}
	cout << mxm << '\n';

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--) {
		solve();
	}
}

/* choose random node, find farthest node to this random node, find distance of the farthest node from this farthest node*/
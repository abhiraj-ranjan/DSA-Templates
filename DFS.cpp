#include<bits/stdc++.h>
using namespace std;
int n, m, q;
vector<vector<int>> g;
int cc[100100];
int vis[100100];
int cc_num_size[100100];

void dfs(int x, int cc_num) {
	vis[x] = 1;
	cc_num_size[cc_num]++;
	cc[x] = cc_num;
	for(auto v: g[x]) {
		if(!vis[v]) {
			dfs(v, cc_num);
		}
	}
	return;
}
void solve() {
	cin >> n >> m >> q;
	g.resize(n + 1);

	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0; i < n + 1; i++) {
		vis[i] = 0;
	}
	int cc_num = 0;
	for(int i = 1; i < n + 1; i++) {
		if (!vis[i]) {
			cc_num++;
			cc_num_size[cc_num] = 0;
			dfs(i, cc_num);
		}
	}
	while(q--) {
		int tmp;
		cin >> tmp;
		if(tmp == 1) {
			int x;
			cin >> x;
			cout << cc_num_size[cc[x]] << '\n';
		}
		if(tmp == 2) {
			int x, y;
			cin >> x >> y;
			if(cc[x] == cc[y]) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}

	}
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
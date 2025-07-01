#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
int n, k;
vector<vector<int>> g;
int dp[110][110];

//dp[u][i] = combination of all 0 to i - 1 sized subtrees of its children vi's
//v0,v1,v2,...,vj children
//dp[u][i] = summ over k from 0 to j (dp[vk][sk]); such that summoverk( sk) = i - 1

void dfs(int u, int p) {
	//inside the dfs, it updates the dp table which fills for each node,
	//the number of subtrees of size j rooted at u
	dp[u][0] = 1;
	int dp_buff[110] = {0};
	dp_buff[0] = 1;
	for(auto v: g[u]) {
		if(v == p) continue;
		dfs(v, u);
		int dp_buff1[110] = {0}; //tmp array

		for(int i = 0; i <= k; i++) {
			for(int j = 0; j <= k - i; j++) {
				dp_buff1[i + j] += dp_buff[i]*dp[v][j];
			}
		}
		for (int i = 0; i <= k; i++) { //update the 'aggregate array'
			dp_buff[i] = dp_buff1[i];
		}
	}
	for(int i = 0; i <= k - 1; i++) dp[u][i + 1] = dp_buff[i];
}

void solve() {
	cin >> n >> k;
	g.resize(n + 1);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	cout << dp[1][k];
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
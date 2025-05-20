#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
typedef pair<int, int> ii;
int n, m;
int dis[200100];
int vis[200100];
vector<vector<ii>> g;   //dist, node
vector<pair<int, ii>> e;
void solve() {
	cin >> n >> m;
	g.resize(n + 1);
	for(int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		g[u].push_back(MP(d, v));
		g[v].push_back(MP(d, u));
		e.push_back(MP(d, MP(u, v)));
	}
	int s;
	cin >> s;
	for(int i = 1; i <= n; i++) {
		dis[i] = 1e18;
		vis[i] = 0;
	}
	//Implement Dijkstra
	priority_queue<ii> pq;
	dis[s] = 0;
	pq.push(MP(0, s));
	while(!pq.empty()) {
		int d = -pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(vis[u]) continue;    // already done
		vis[u] = 1;
		for(auto v: g[u]) {
			if(dis[v.second] > dis[u] + v.first) {
				dis[v.second] = dis[u] + v.first;
				pq.push(MP(-dis[v.second], v.second));
			}
		}
	}
	int ans = 0;
	for(auto x: e) {
		int u = x.second.first, v = x.second.second, d = x.first;
		int du = dis[u], dv = dis[v];
		int delta = abs(du - dv);
		if (delta >= d) {
			ans = max(ans, 10 * (min(du, dv) + d));
		} else {
			int rem = d - delta;
			ans = max(ans, 10 * max(du, dv) + 5 * rem);
		}
	}
	cout << ans << '\n';
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
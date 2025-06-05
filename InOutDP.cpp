#include<bits/stdc++.h>
using namespace std;
#define int long long
//maintain a sum of all siblings indp
int n;
int a[100100];
int indp[100100];
int subSum[100100];
int outdp[100100];

vector<vector<int>> g;


void SubSumDFS(int node, int par) {
	//get sum of Ai's present inside the subtree (including root node)
	subSum[node] = a[node];
	for(auto v: g[node]) {
		if(v==par) continue;
		SubSumDFS(v, node);
		subSum[node] += subSum[v];
	}
	return;
}

//default root at 1
void dfsin(int node, int par) {
	//cost of subtree with node as root
	indp[node] = 0;
	for(auto v: g[node]) {
		if(v==par) continue;
		dfsin(v, node);
		indp[node] += indp[v] + subSum[v];
	}
	return;
}

void dfsout(int node, int par) {
	//cost of outer subtree with node as root
	//dfsOut of node = dfsOut of par + sum + dfsIn of par - dfsin of node - subsum(node)
	if(node == 1) {
		outdp[node] = 0;
	}
	else {
		int ans = 0;
		ans += outdp[par];
		ans += subSum[1] - subSum[node];
		ans += indp[par];
		ans -= indp[node];
		ans -= subSum[node];
		outdp[node] = ans;
	}
	for(auto v: g[node]) {
		if(v==par) continue;
		dfsout(v, node);
	}
	return;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	g.resize(n + 1);
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	SubSumDFS(1, 0);
	dfsin(1, 0);
	dfsout(1, 0);
	int mxm = 0, mnm = 1e18;
	for(int i = 1; i <= n; i++) {
		mxm = max(mxm, indp[i]+outdp[i]);
		mnm = min(mnm, indp[i]+outdp[i]);
	}
	cout << mxm << ' ' << mnm << '\n';
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
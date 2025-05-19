#include<bits/stdc++.h>
using namespace std;
int n, m;
string g[1010];
vector<pair<int, int>> mAdd;
int mDis[1010][1010];
int sDis[1010][1010];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
pair<int, int> s;
void solve() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> g[i];
		for(int j = 0; j < m; j++) {
			mDis[i][j] = 1e9;
			sDis[i][j] = 1e9;
			if(g[i][j] == 'M') {
				mAdd.push_back({i, j});
			}
			if(g[i][j] == 'A') {
				s = {i, j};
			}
		}
	}
	//multisourse_BFS
	queue<pair<int, int>> q;
	for(auto v: mAdd) {
		int i = v.first, j = v.second;
		mDis[i][j] = 0;
		q.push({i, j});
	}
	while(!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(g[nx][ny] == '#') continue;
			if(mDis[nx][ny] != 1e9) continue;
			mDis[nx][ny] = mDis[x][y] + 1;
			q.push({nx, ny});
		}
	}
	//now every pixel contains dis from any of the M's
	//q is empty now
	q.push(s);
	sDis[s.first][s.second] = 0;
	while(!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(g[nx][ny] == '#') continue;
			if(sDis[nx][ny] != 1e9) continue;
			sDis[nx][ny] = sDis[x][y] + 1;
			q.push({nx, ny});
		}
	}
	int ans = 1e9;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i > 0 && i < n - 1 && j > 0 && j < m - 1) continue;
			if(sDis[i][j] >= mDis[i][j]) continue;   // or equal to
			ans = min(ans, sDis[i][j]);
		}
	}
	if (ans != 1e9) {
		cout << "YES\n" << ans << '\n';
	}
	else {
		cout << "NO\n";
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

/*****************************************
----PRINTING PATH---
string path = "";
int x = finx, y = finy;
while(true) {
    int prex = par[x][y].first;
    int prey = par[x][y].second;
    if(prex == -1 && prey == -1) break;
    if(y - prey == 1) path += 'R';
    else if(y - prey == -1) path += 'L';
    else if(x - prex == 1) path += 'D';
    else path += 'U';
    x = prex; y = prey;
}
reverse(path.begin(), path.end());
cout << path << "\n";
******************************************/
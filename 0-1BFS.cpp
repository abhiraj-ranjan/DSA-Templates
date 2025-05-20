#include<bits/stdc++.h>
using namespace std;
int n, m;
int g[1010][1010];
int dis[1010][1010];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
pair<int, int> dict[] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> g[i][j];
			dis[i][j] = 1e9;
		}
	}
	dis[1][1] = 0;
	deque<pair<int, int>> dq;
	dq.push_back({1, 1});
	while(!dq.empty()) {
		pair<int, int> tmp = dq.front();
		int x = tmp.first, y = tmp.second;
		dq.pop_front();
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if(make_pair(nx - x, ny - y) == dict[g[x][y]]) {
				//0 weight
				if(dis[nx][ny] > dis[x][y]) {
					dis[nx][ny] = dis[x][y];
					dq.push_front({nx, ny});
				}
			}
			else {
				//1 weight
				if(dis[nx][ny] > dis[x][y] + 1) {
					dis[nx][ny] = dis[x][y] + 1;
					dq.push_back({nx, ny});
				}
			}
		}
	}
	cout << dis[n][m] << '\n';
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
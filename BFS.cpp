#include<bits/stdc++.h>
using namespace std;
int n, sx, sy, fx, fy;
string g[1010];
int dis[1010][1010];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void solve(){
    cin >> n >> sx >> sy >> fx >> fy;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dis[i][j] = 1e9;
        }
    }
    pair<int, int> mov[] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}};
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dis[sx][sy] = 0;
    while(!q.empty()){
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        for(auto v: mov){
            int dx = v.first, dy = v.second;
            int nx = ux + dx, ny = uy + dy;
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (dis[nx][ny] != 1e9) continue;
            dis[nx][ny] = dis[ux][uy] + 1;
            q.push({nx, ny});
        }
    }
    int ans = dis[fx][fy];
    if(ans == 1e9){
        cout << -1 << '\n';
    }
    else{
        cout << ans << '\n';
    }

    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
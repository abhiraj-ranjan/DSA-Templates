#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int n1, n2;
int dp[3010][3010];
int rec(int i, int j) {
	if(i == n1 || j == n2) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int ans = 0;
	if(s1[i] == s2[j]) {
		ans = 1 + rec(i + 1, j + 1);
		//ans is increasing only due to this
		//hence gen soln only when this is satisfied
	}
	else {
		ans = max(rec(i + 1, j), rec(i, j + 1));
	}

	return dp[i][j] = ans;
}

void gen(int i, int j) {
	if(i == n1 || j == n2) return;
	if(s1[i] == s2[j]) {
		cout << s1[i];
		gen(i + 1, j + 1);
	}
	else {
		if(rec(i + 1, j) > rec(i, j + 1)) {
			gen(i + 1, j);
		}
		else {
			gen(i, j + 1);
		}
	}
}

void solve() {
	cin >> s1 >> s2;

	n1 = s1.length();
	n2 = s2.length();

	for(int i = 0; i < n1; i++) {
		for(int j = 0; j < n2; j++) {
			dp[i][j] = -1;
		}
	}

	gen(0, 0);
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


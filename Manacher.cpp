#include<bits/stdc++.h>
using namespace std;
int n;
string s;

struct manacher {
	vector<int> p;
	void run_manacher(string s) {
		int n = s.length();// length of padded string t
		p.assign(n, 1);
		int l = 1, r = 1;
		for(int i = 1; i < n; i++) {
			p[i] = max(0, min(r - i, p[l + r - i]));
			while ((i - p[i] >= 0 && i + p[i] < n)&&(s[i - p[i]] == s[i + p[i]])) p[i]++;
			if(i + p[i] > r) {
				l = i - p[i];
				r = i + p[i];
			}
		}

	}
	void build(string s) {
		string t;
		for(auto v: s) {
			t += "#";
			t += v;
		}
		t += "#";
		run_manacher(t);
	}
};

void solve() {
	cin >> n >> s;
	manacher m;
	m.build(s);
	for(auto v: m.p) {
		cout << v << ' ';
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
#include<bits/stdc++.h>
using namespace std;
int n;
string s;

void solve() {
	cin >> n >> s;
	int kmp[n + 1];
	int i = 0, j = -1;
	kmp[0] = -1;
	while(i < n) {
		while(j != -1 && s[i]!= s[j]) j = kmp[j];
		i++;
		j++;
		kmp[i] = j;
	}
	int period = 0;
	for(int i = 1; i <= n; i++) {
		if(kmp[i]) break;
		period++;
	}

	for(int i = 1; i <= n; i++) {
		if(i%period || i == period)continue;
		if(kmp[i] == i - period) {
			//it is a periodic substring
			cout << i << ' ' << i/period << '\n';
		}
	}

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	int tmp = 1;
	while(t--) {
		cout << "Test case #" << tmp << '\n';
		solve();
		tmp++;
		cout << '\n';
	}
}
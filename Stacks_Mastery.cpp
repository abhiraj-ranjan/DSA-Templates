#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100], l[100100], r[100100], p[100100];

void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		p[i] = 0;
	}
	p[n] = 0;
	stack<int> sL, sR;
	for(int i = 0; i < n; i++) {
		int j = n - 1 - i;
		while(!sL.empty() && a[sL.top()] >= a[i]) sL.pop();
		// we want nearest index less than a[i]; so used greater than equal to (opp)
		while(!sR.empty() && a[sR.top()] >= a[j]) sR.pop();
		if(sL.empty()) l[i] = -1;
		else l[i] = sL.top();
		if(sR.empty()) r[j] = n;
		else r[j] = sR.top();
		sL.push(i);
		sR.push(j);
	}

	for(int i = 0; i < n; i++) {
		int nL = l[i];
		int nR = r[i];
		nR--;
		nL++;
		p[nR - nL + 1] = max(p[nR - nL + 1], a[i]);
	}
	for(int i = n; i >= 0; i--) {
		p[i] = max(p[i + 1], p[i]);
	}
	for(int i = 1; i <= n; i++) {
		cout << p[i] << ' ';
	}

	cout << '\n';
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--) {
		solve();
	}
}
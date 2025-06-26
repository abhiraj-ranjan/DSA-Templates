#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000100];
int fen[100100];

//fenwick tree implementation
//fenwick trees are used when you need to find range sums along with point updates quickly. Segment tree might be an overkill for these questions, so use fenwick tree
//note fenwick tree works only for this specific case, for other cases, segment tree will work as it is general
//will build a fenwick tree over freq array, fen[i] stores frequencies of a certain range, note fenwick tree uses 1 based indexing
void update( int pos, int val) {
	//add val to pos's value and update the fen tree
	for(int i = pos; i < 100100; i += (i & -i)) fen[i] += val;
}

int sum(int x) {
	//get the prefix sum in log(n) from 1 to x
	int ans = 0;
	for(int i = x; i >= 1; i -= (i&(-i))) ans+= fen[i];
	return ans;
}
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]++; //since 1 based indexing
	}
	memset(fen, 0, sizeof(fen)); //initialize
	int ans = 0;
	for(int i = 0; i < n; i++) {
		//inserting ith element
		update(a[i], 1);
		//add cost
		ans += min(sum(a[i] - 1), sum(100001) - sum(a[i]));
	}
	cout << ans << '\n';
	return;

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
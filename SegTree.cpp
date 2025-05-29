#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
int a[200100];
int t[800400];  //instead of struct node, can also use this, if problem is simple

int merge(int n1, int n2) {
	//return the merged node (here just an int)
	return t[n1]+t[n2];
}

void build(int idx, int l, int r) {
	//initially builds the whole seg tree,
	//ANY NODE IN A SEG TREE MUST HAVE 3 PARAS -> IDX, L, R;
	if(l == r) {
		// is a leaf -> base case for build
		t[idx] = a[l];
		return;
	}
	int mid = ( l + r )/2 ;
	build(2*idx, l, mid);
	build(2*idx + 1, mid + 1, r);
	t[idx] = merge(2*idx, 2*idx + 1);
	return;
}

void update(int idx, int l, int r, int pos, int val) {
	//pruning for update
	if(pos < l || pos > r) return;
	if(l == r) {
		//pruning for build
		t[idx] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(2*idx, l, mid, pos, val);
	update(2*idx + 1, mid + 1, r, pos, val);
	t[idx] = merge(2*idx, 2*idx + 1);
	return;
}

int find(int idx, int l, int r, int lq, int rq) {
	//for the given node, find the contribution of this node for the range sum asked
	//pruning for find
	if(rq < l || r < lq) return 0;
	//base case for find -> note that here, is a leaf would also work, but will lead to redundant recursions, if below condition is met, therefore inefficient
	//here we use a better base case for find
	if(lq <= l && r <= rq) {
		//lq==rq
		return t[idx];
	}
	int mid = (l + r) / 2;
	return find(2*idx, l, mid, lq, rq) + find(2*idx + 1, mid + 1, r, lq, rq);
}

void solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//build the given seg tree
	build(1, 1, n);
	while(q--) {
		int c;
		cin >> c;
		if(c == 1) {
			//update
			int i, x;
			cin >> i >> x;
			update(1, 1, n, i, x);
		}
		else {
			//range query
			int i, j;
			cin >> i >> j;
			cout << find(1, 1, n, i, j) << '\n';
		}
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
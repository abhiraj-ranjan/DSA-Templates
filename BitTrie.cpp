#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];

struct node {
	int left, right;
	// left -> 0; right -> 1;
	node() {
		left = -1;
		right = -1;
	}
};

struct trie {
	vector<node> nodes;
	trie() {
		node rootnode;
		nodes.push_back(rootnode);
	}
	void insert(int num) {
		int curr_node_idx = 0;
		for(int i = 20; i >= 0; i--) {
			if(num&(1<<i)) {
				//if num has ith bit set
				if(nodes[curr_node_idx].right == -1) {
					//create a new edge
					node newNode;
					nodes.push_back(newNode);
					nodes[curr_node_idx].right = nodes.size() - 1;
				}
			}
			else {
				//num has ith bit not set
				if(nodes[curr_node_idx].left == -1) {
					node newNode;
					nodes.push_back(newNode);
					nodes[curr_node_idx].left = nodes.size() - 1;
				}
			}
			curr_node_idx = (num & (1 << i)) ? nodes[curr_node_idx].right : nodes[curr_node_idx].left;
		}
	}
};
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		a[i] = 0;
	}
	for(int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if(i == 0) a[i] = tmp;
		else a[i] = a[i-1]^tmp;

	}
	trie t;
	int mxm = 0;
	t.insert(a[0]);
	for(int i = 1; i < n; i++) {
		int curr_node_idx = 0;
		int ans = 0;
		for(int j = 20; j >= 0; j--) {
			if(a[i]&(1<<j)) {
				//if ai has jth bit set
				if(t.nodes[curr_node_idx].left!=-1) {
					//go there
					curr_node_idx = t.nodes[curr_node_idx].left;
					ans += (1<<j);
				}
				else {
					curr_node_idx = t.nodes[curr_node_idx].right;
				}
			}
			else {
				//ai has jth bit not set
				if(t.nodes[curr_node_idx].right!=-1) {
					//go there
					curr_node_idx = t.nodes[curr_node_idx].right;
					ans += (1<<j);
				}
				else {
					curr_node_idx = t.nodes[curr_node_idx].left;
				}
			}
		}
		mxm = max(mxm, ans);
		t.insert(a[i]);
	}
	cout << mxm << '\n';

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
#include<bits/stdc++.h>
using namespace std;
int n, l, q;
string a[10010];    //stores the words

struct node {
	int child[26]; //for 26 possible children (alphabets)
	vector<int> id; //will store the indices of words this node i a prefix of
	node() {
		memset(child, -1, sizeof(child)); //initialize the node with no children
	}
};

struct trie {
	vector<node>nodes;// will store the nodes here
	trie() {
		node rootNode;
		//fill here for the root node if reqd

		nodes.push_back(rootNode);  //initialize trie with a node as root node
	}
	void insert(string s, int idx) {
		int curr_node_idx = 0; // points to the nodes array, currently at root node (0 idx)
		for(int i = 0; i < s.length(); i++) {
			if(nodes[curr_node_idx].child[s[i] - 'a'] == -1) {
				//new character
				node newNode;
				//modify the newNode here

				nodes.push_back(newNode);
				nodes[curr_node_idx].child[s[i] - 'a'] = nodes.size() - 1; // assign newNode as children of the curr_node_idx
			}
			//process the node here before going to the child
			nodes[curr_node_idx].id.push_back(idx); //push the idx of the word it is a suffix of

			curr_node_idx = nodes[curr_node_idx].child[s[i] - 'a'];
		}
		//end the string/ mark the end as a tag here
		nodes[curr_node_idx].id.push_back(idx);
	}
};

void solve() {
	cin >> n >> l >> q;
	for(int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		cin >> a[i];
	}
	sort(a, a + n);
	//dictionary contains words in sorted order
	trie t;
	for(int i = 0; i < n; i++) {
		t.insert(a[i], i);
	}
	//now the trie is built
	//each node of the trie contains indices of the words it is a prefix of
	//now handle queries
	while(q--) {
		int tmp, k;
		string s;
		cin >> tmp >> s >> k;
		int curr_node_idx = 0;
		for(int i = 0; i < tmp; i++) {
			curr_node_idx = t.nodes[curr_node_idx].child[s[i] - 'a'];
			//break if -1 (no node)
			if(curr_node_idx == -1) break;
			int cnt = 0;
			for(auto idx: t.nodes[curr_node_idx].id) {
				if(cnt >= k) break;
				cout << a[idx] << ' ';
				cnt++;
			}
			cout << '\n';
		}
		cout << '\n';
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
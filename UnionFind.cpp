#include <iostream>
using namespace std;

class UnionFind {
	int n, set_size;
	int *parent, *rank;

public:
	UnionFind() {}

	UnionFind(int a) {
		n = set_size = a;
		parent = new int[n + 1];
		rank = new int[n + 1];
		for (int i = 1; i <= n; ++i) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int find(int x) {
		if (x != parent[x])
			parent[x] = find(parent[x]); // Path compression
		return parent[x];
	}

	void merge(int x, int y) {
		int xroot = find(x), yroot = find(y);
		if (xroot != yroot) {
			if (rank[xroot] >= rank[yroot]) {
				parent[yroot] = xroot;
				rank[xroot] += rank[yroot];
			} else {
				parent[xroot] = yroot;
				rank[yroot] += rank[xroot];
			}
			set_size -= 1;
		}
	}

	void reset() {
		set_size = n;
		for (int i = 1; i <= n; ++i) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int size() {
		return set_size;
	}

	~UnionFind() {
		delete[] parent;
		delete[] rank;
	}
};

// Example usage:
int main() {
	UnionFind uf(5); // Create 5 disjoint sets: 1, 2, 3, 4, 5

	uf.merge(1, 2);
	uf.merge(3, 4);
	uf.merge(2, 3);

	cout << "Set size: " << uf.size() << endl; // Output should be 2

	cout << "Find(1): " << uf.find(1) << endl;
	cout << "Find(4): " << uf.find(4) << endl;
	cout << "Find(5): " << uf.find(5) << endl;

	return 0;
}
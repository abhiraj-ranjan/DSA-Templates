#include <bits/stdc++.h>
using namespace std;

struct node {
    int sum = 0;
    int is_lazy = 0; 
    node(int a = 0) {
        sum = a;
        is_lazy = 0;
    }
};

node merge(node a, node b) {
    return node(a.sum + b.sum); 
}

node t[800800];
int a[200200];
int n, q;

void build(int index, int l, int r) {
    //Build logic is same
    if (l == r) {
        t[index] = node(a[l]); 
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index + 1, l, mid);
    build(2 * index + 2, mid + 1, r);
    t[index] = merge(t[2 * index + 1], t[2 * index + 2]);
}

void push(int index, int l, int r) {
    //for push ->
        //first update the current index
        //then if not a leaf, then propogate the tag to children
        //then unlazy current idx
    t[index].sum += t[index].is_lazy * (r - l + 1) * (r - l + 2) / 2; 
    if (l != r) {
        t[2 * index + 1].is_lazy += t[index].is_lazy;
        t[2 * index + 2].is_lazy += t[index].is_lazy;
    }
    t[index].is_lazy = 0;
}

void update(int index, int l, int r, int lq, int rq) {
    //push first
    push(index, l, r);
    if (lq > r || l > rq) return;
    if (lq <= l && r <= rq) {
        t[index].is_lazy++;
        //push before returning (MUST), since it might be that its parent requires to be merged, so we need a correct value.
        push(index, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index + 1, l, mid, lq, rq);
    update(2 * index + 2, mid + 1, r, lq, rq);
    t[index] = merge(t[2 * index + 1], t[2 * index + 2]);
}

node query(int index, int l, int r, int lq, int rq) {
    //push first
    push(index, l, r);
    if (lq > r || l > rq) return node(0); 
    if (lq <= l && r <= rq) return t[index];
    int mid = (l + r) / 2;
    return merge(query(2 * index + 1, l, mid, lq, rq), query(2 * index + 2, mid + 1, r, lq, rq));
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while (q--) {
        int ch;
        cin >> ch;
        if (ch == 1) {
            int lq, rq;
            cin >> lq >> rq;
            lq--; rq--;
            update(1, 0, n - 1, lq, rq);
        } else {
            int lq, rq;
            cin >> lq >> rq;
            lq--; rq--;
            node ans = query(1, 0, n - 1, lq, rq);
            cout << ans.sum << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--){
    solve(); 
    }
}
#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[100100];
// MONOTONE DEQUE TEMPLATE
struct monotone_dq{
    //this monotone dq stores in descending order
    deque<int> dq;
    void insert(int x){
        while(!dq.empty() && dq.back() < x){   // dont do dq.back()<= x
            dq.pop_back();
        }
        dq.push_back(x);
        return;
    }
    void erase(int x){
        // if front is not x, then it is already erased
        //simulate to prove
        //say whenever x was inserted, it would have removed all smaller elements present in dq, it would add in the back of dq, with elements to its left being greater than x and added before x, so they will be removed before x
        // now if on adding elements ahead of it, we add any element >x, then we are sure x will get deleted, 
        //suppose we want to now, erase this x, we now that all elements which were initially to its left (on its insertion) would have been erased, cause they were added before, 
        //then it must be in the front, which tells that all elements added after it are greater than it, else it would have been deleted.
        if (dq.front() == x){
            dq.pop_front();
        }
        return;
    }
    int getMax(){
        return dq.front();
    }
};
void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    monotone_dq m_dq;

    for(int i = 0; i < n; i++){
        m_dq.insert(a[i]);  //insert the element
        if(i >= k) m_dq.erase(a[i - k]);    //erase the last element of the window after i reaches k (everytime henceforward)
        if(i >= k - 1) cout << m_dq.getMax() << ' ';   //get window result after i reaches k - 1 (everytime henceforward)
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout << '\n';
    }
}
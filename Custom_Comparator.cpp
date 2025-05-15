#include<bits/stdc++.h>
using namespace std;
int n;
pair<int, int> p[1010];
bool comp(pair<int, int> a, pair<int, int> b){
    // condition true for a before b
    return a.first + a.second > b.first + b.second;
    //  dont use >= or <= 
}

void solve(){
    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> p[i].first;
    for(int i = 0 ; i < n; i++) cin >> p[i].second;
    sort(p, p + n, comp);
    int p1 = 0, p2 = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) p1 += p[i].first;
        else p2 += p[i].second; 
    }
    if(p1 > p2) cout << "Alice" << '\n';
    else if (p2 > p1) cout << "Bob" << '\n'; 
    else cout << "Tie" << '\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
int n, x;
int arr[1010];
map<int, int> mp;

void solve(){
    cin >> n >> x;
    for(int i = 0;i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    mp[arr[n-2] + arr[n-1]] = 1;
    for(int b = n - 3; b > 0; b--){
        //find a for this b
        for(int a = 0; a < b; a++){
            if(mp[x - arr[a] - arr[b]]){
                cout << "YES" << '\n';
                return;
            }
        }
        //couldn't find, proceed
        for(int d = b + 1; d < n; d++){
            mp[arr[b]+arr[d]]++;
        }
    }
    cout << "NO" << '\n';
    return;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}


/*
- - - - - - - - - - - -
^       ^|    ...(c,d) |  
a   <-- b|    ...(c,d) | 

move b in this direction
merge b in c,d pair sum at each move of b
*/
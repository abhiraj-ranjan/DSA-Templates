
#include <bits/stdc++.h>
using namespace std;

void sort(int a[], int n)
//DUTCH NATIONAL FLAG ALGORITHM
{
    int lo = 0, hi = n - 1, i = 0;
    //lo -> 1st element from the start that is not 0;
    //hi -> 1st element from the end that is not 2;
    while(i <= hi){
        //first check for shifting to the right
        if(a[i] == 0){
            swap(a[i], a[lo]);
            i++;
            lo++;
        }
        //then check shifting to the left
        else if (a[i] == 2){
            swap(a[i], a[hi]);
            hi--;
        }
        //then no shifting
        else{
            i++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, n);
    for (int i : a)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}

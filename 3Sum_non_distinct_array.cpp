//template for 3Sum with non distinct array
void solve(){
    //take inputs
    for(int j = 0; j < n; j++){
        int i = 0, k = n - 1;
        while(i < j && j < k){
            if(a[i]+a[j]+a[k] == targ){
                int itemp = i, ktemp = k;
                while(itemp < j && a[itemp]==a[i]){
                    itemp++;
                }
                while(ktemp > j && a[ktemp] == a[k]){
                    ktemp--;
                }
                int icnt = itemp - i;
                int kcnt = ktemp - k;
                ans += kcnt*icnt;
                i = itemp;
                k = ktemp;
            }
            else if (a[i]+a[j]+a[k] < targ){
                i++;
            }
            else{
                k--;
            }
        }
    }
}
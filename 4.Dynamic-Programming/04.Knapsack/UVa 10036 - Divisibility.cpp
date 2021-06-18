#include <bits/stdc++.h>

using namespace std;

int t, n, k, arr[10001], dp[10001][101];

int fix(int a){
    return (a%k + k)%k;
}

int check(int i, int mod){
    if(i==n) return !mod;

    int &ret = dp[i][mod];
    if(~ret) return ret;

    return ret = check(i+1, fix(mod+arr[i])) | check(i+1, fix(mod-arr[i]));
}

int main(){

    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=0; i<n; i++)
            cin >> arr[i];

        memset(dp, -1, sizeof dp);
        cout << (check(1, fix(arr[0]+k)) ? "Divisible\n" : "Not divisible\n");
    }
    return 0;
}

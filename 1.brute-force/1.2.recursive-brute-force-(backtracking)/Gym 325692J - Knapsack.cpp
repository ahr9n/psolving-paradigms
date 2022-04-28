#include <bits/stdc++.h>

using namespace std;

int n, w, tot, ans;
const int N = 109, V = 1e5 + 9;
long long a[N][2], dp[N][V]; // :D

long long sol(int i, int v){ // returns the tot_weight
    if(!v) return 0;
    if(v<0 || i==n) return 1E9;

    long long &ret = dp[i][v];
    if(~ret) return ret;

    return ret = min(a[i][0]+sol(i+1, v-a[i][1]), sol(i+1, v));
}

int main(){
    cin >> n >> w;
    for(int i=0; i<n; i++)
        cin >> a[i][0] >> a[i][1], tot += a[i][1];

    memset(dp, -1, sizeof dp);
    for(int i=0; i<=tot; i++)
        if(sol(0, i) <= w) ans = i;

    cout << ans;
}

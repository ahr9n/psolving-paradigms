#include <bits/stdc++.h>

using namespace std;

int n;
const int N = 109, W = 1e5 + 9;
long long a[N][2], dp[N][W];

long long sol(int i, long long w){
    if(w<0) return -1E9;
    if(i==n) return 0;

    long long &ret = dp[i][w];
    if(~ret) return ret;

    return ret = max(a[i][1]+sol(i+1, w-a[i][0]), sol(i+1, w));
}

int main(){

    int w; cin >> n >> w;
    for(int i=0; i<n; i++)
        cin >> a[i][0] >> a[i][1];

    memset(dp, -1, sizeof dp);
    cout << sol(0, w);
}

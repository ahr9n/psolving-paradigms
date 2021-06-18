#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 2E5 + 5, K = 21, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
int n, a, dp[N], d[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.precision(9);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a;
        
        dp[a] = d[a] = 1;
        for (int j = 2; j*j <= a; ++j) {
            if(a % j) continue;
            dp[a] = max({dp[a], d[j]+1, d[a/j]+1});
        }
        
        for (int j = 2; j*j <= a; ++j) {
            if(a % j) continue;
            d[j] = d[a/j] = dp[a];
        }
        
    }
    
    cout << *max_element(dp, dp+N);

    return 0;
}

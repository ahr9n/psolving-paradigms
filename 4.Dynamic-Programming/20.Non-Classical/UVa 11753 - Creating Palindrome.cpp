#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 2E5 + 5, K = 21, MOD = 1E9 + 7, OO = 0x3f3f3f3f;;
int t, n, k, ans;
int a[N], mem[N][K][K];

int dp(int i, int k1, int k2){
    if(k1 + k2 > k) return k1 + k2;

    int j = n-1 - i - k1 + k2;
    if(i >= j) return 0;

    int &ret = mem[i][k1][k2];
    if(~ret) return ret;

    return ret = (a[i] == a[j] ? dp(i+1, k1, k2) : 1 + min(dp(i+1, k1, k2+1), dp(i, k1+1, k2)));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.precision(9);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> t;
    for (int test = 1; test <= t; ++test) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> a[i];
        memset(mem, -1, n * sizeof mem[0]);
        ans = dp(0, 0, 0);

        cout << "Case " << test << ": ";
        if(!ans) cout << "Too easy\n";
        else if(ans > k) cout << "Too difficult\n";
        else cout << ans << '\n';
    }

    return 0;
}

#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 2E5 + 5, MOD = 1E9 + 7, OO = 0x3f3f3f3f;

ll bigPow(ll base, ll power) {
    if (power == 0) return 1;
    if (power == 1) return base;

    ll ans = bigPow(base, power / 2);
    ans = ((ans % MOD) * (ans % MOD)) % MOD;

    if (power & 1) return ((ans % MOD) * (base % MOD)) % MOD;
    return ans;
}

int t, n, k, dp[N];
int tie0, tie1, win;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> t;
    while (t--) {
        cin >> n >> k;

        dp[0] = 1;
        for (int i = 1; i <= k; ++i) {
            if (n & 1) {
                win = 0;
                tie0 = bigPow(2, n - 1) * dp[i - 1] % MOD;
                tie1 = dp[i - 1];
            } else {
                win = bigPow(2, 1LL * n * (i - 1));
                tie0 = (bigPow(2, n - 1) - 1) * dp[i - 1] % MOD;
                tie1 = 0;
            }
            dp[i] = (1LL * tie1 + tie0 + win) % MOD;
        }

        cout << dp[k] << '\n';
    }


    return 0;
}

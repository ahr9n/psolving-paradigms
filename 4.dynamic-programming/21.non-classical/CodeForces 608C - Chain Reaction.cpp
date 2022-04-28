#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 10, M = 4 * N, OO = 0x3f3f3f3f;
int n, idx;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end());

    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        idx = lower_bound(a.begin(), a.end(), pair<int, int>{a[i].first - a[i].second, -1}) - a.begin();
        dp[i + 1] = dp[idx] + 1;
    }

    cout << n - *max_element(dp.begin(), dp.end());
    return 0;
}

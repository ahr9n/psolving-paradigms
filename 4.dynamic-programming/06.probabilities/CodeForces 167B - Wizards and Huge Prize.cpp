#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 2E5 + 5, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
int n, k, l;
ld memo[201][201][201];
vector<pair<int, ld>> a;

ld dp(int i, int k, int countWin) {
    if (k < 0) return 0.0;
    if (i == n) return countWin <= 0;

    ld &ret = memo[i][k][countWin];
    if (ret != -1) return ret;

    ret = (1.0 - (a[i].second / 100.0)) * dp(i + 1, k, countWin);
    ret += (a[i].second / 100.0) * dp(i + 1, min(200, k + a[i].first), max(0, countWin - 1));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n >> l >> k, a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i].second;
    for (int i = 0; i < n; ++i) cin >> a[i].first;

    sort(a.rbegin(), a.rend());

    //    memset(memo, -1, sizeof memo)  bad memset :(
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= 200; ++j)
            for (int k = 0; k <= l; ++k)
                memo[i][j][k] = -1;

    cout << fixed << setprecision(12) << dp(0, k, l);

    return 0;
}

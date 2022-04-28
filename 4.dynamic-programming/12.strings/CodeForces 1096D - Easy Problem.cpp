#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 2E5 + 5, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;

ll n, a[N], mem[N][4];
string s, hard;

ll dp(int i, int j) {
    if (i == -1) return 0;
    if (j == -1) return 1e18;

    ll &ret = mem[i][j];
    if (~ret) return ret;

    if (s[i] == hard[j])
        ret = min(dp(i - 1, j) + a[i], dp(i, j - 1));
    else
        ret = dp(i - 1, j);

    return ret;
}

void solve() {
    hard = "hard";
    memset(mem, -1, sizeof(mem));
    cout << dp(n - 1, 3);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n >> s;
    for (int i = 0; i < n; ++i) cin >> a[i];
    solve();

    return 0;
}

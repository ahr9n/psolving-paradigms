#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

const int N = 3E5 + 5, M = 1E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
int n;
string s;

int memo[501][501];

// nested ranges style 
int dp(int l, int r) {
    if (l == r) return 1;
    if (l > r) return 0;

    int &ret = memo[l][r];
    if (~ret) return ret;

    ret = 1 + dp(l + 1, r);
    for (int i = l; i <= r; ++i)
        if (s[l] == s[i])
            ret = min(ret, dp(l + 1, i - 1) + dp(i, r));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n >> s;
    memset(memo, -1, sizeof memo);

    cout << dp(0, n - 1);

    return 0;
}v

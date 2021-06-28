#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 201, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
ll mem[N];
int n, t;
string s;

ll dp(int i) {
    if (i == n) return 0;

    ll &ret = mem[i];
    if (~ret) return ret;

    ll sum = 0;
    for (int j = i; j < n; ++j) {
        if (sum * 10 + s[j] - '0' > INT_MAX) break;
        sum = sum * 10 + s[j] - '0';
        ret = max(ret, dp(j + 1) + sum);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> t;
    while (t--) {
        cin >> s, n = s.size();

        memset(mem, -1, sizeof mem);
        cout << dp(0) << '\n';
    }

    return 0;
}

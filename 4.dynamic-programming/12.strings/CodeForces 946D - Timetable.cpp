#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

const int N = 505, K = N, MOD = 1E9 + 7, OO = 0x3f3f3f3f;

int n, m, mem[N][K];
string s[N];
vector<vector<int>> active, hours;

int dp(int idx, int rem) {
    if (idx == n) return 0;

    int &ret = mem[idx][rem];
    if (~ret) return ret;

    ret = OO;
    for (int i = 0; i <= active[idx].size(); ++i) {
        if(i > rem) break;
        ret = min(ret, hours[idx][active[idx].size() - i] + dp(idx + 1, rem - i));
    }

    return ret;
}

void preCalc() {
    active.resize(n), hours.resize(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '1') active[i].push_back(j);

        hours[i].resize(active[i].size() + 1);
        for (int j = 1; j <= active[i].size(); ++j) {
            hours[i][j] = OO;
            for (int k = 0; k <= active[i].size() - j; ++k)
                hours[i][j] = min(hours[i][j], active[i][k + j - 1] - active[i][k] + 1);
        }
    }
}

int k;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> s[i];

    preCalc();

    memset(mem, -1, sizeof mem);
    cout << dp(0, k);

    return 0;
}

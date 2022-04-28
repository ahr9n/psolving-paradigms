#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 2E5 + 5, M = 1E6 + 5, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
string s, t;

int memo[M][2];
int dp(int i, int cur) {
    if (i == s.size()) return memo[i][cur] = 1;

    int &ret = memo[i][cur];
    if (~ret) return ret;

    ret = 0;
    if (!cur) ret |= dp(i + 1, 1);
    if (s[i] == t[i - cur]) ret |= dp(i + 1, cur);

    return ret;
}

vector<int> ans;
void build(int i, int cur = 0) {
    if (i == s.size()) return;

    if (memo[i + 1][1] == 1) ans.push_back(i + 1);
    if (s[i] == t[i]) build(i + 1, 0);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> s >> t;

    memset(memo, -1, sizeof memo);
    for (int i = (int)s.size() - 1; i >= 0; --i) dp(i, 0), dp(i, 1);
    build(0);

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i + 1 == ans.size()];

    return 0;
}

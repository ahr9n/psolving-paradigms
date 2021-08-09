#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 2E5 + 5, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
int dp['z'+1]['z'+1], n, ans;
string s;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n;
    memset(dp, -1, sizeof dp);
    while (n--){
        cin >> s;
        for (int i = 'a'; i <= 'z'; ++i)
            if(~dp[i][s.front()]) dp[i][s.back()] = max(dp[i][s.back()], dp[i][s.front()] + (int)s.size());
        dp[s.front()][s.back()] = max(dp[s.front()][s.back()], (int)s.size());
    }

    for (int i = 'a'; i <= 'z'; ++i) ans = max(ans, dp[i][i]);

    cout << ans;

    return 0;
}

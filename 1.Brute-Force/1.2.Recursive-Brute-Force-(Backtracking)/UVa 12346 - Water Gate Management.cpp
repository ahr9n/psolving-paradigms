#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 25, M = 1e3 + 5, OO = 0x3f3f3f3f;
int n, m;
map<pair<int, ll>, ll> memo;
ll flow[N], cost[N], volume, hour;

ll dp(int i, ll sum){
    if(i == n) return (sum*hour >= volume ? 0 : 1e18);

    if(memo.count({i, sum})) return memo[{i, sum}];

    return memo[{i, sum}] = min(dp(i+1, sum), cost[i] + dp(i+1, sum+flow[i]));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> flow[i] >> cost[i];

    cin >> m;
    for(int test = 1; test <= m; ++test){
        cout << "Case " << test << ": ";

        cin >> volume >> hour;

        memo.clear();
        if(dp(0, 0) == 1e18) cout << "IMPOSSIBLE\n";
        else cout << dp(0, 0) << '\n';
    }

    return 0;
}

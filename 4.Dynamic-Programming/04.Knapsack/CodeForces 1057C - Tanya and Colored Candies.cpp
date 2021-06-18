#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 55, K = 2055, OO = 0x3f3f3f3f;
int n, s, k, a[N], memo[N][K], ans;
string color;

int dp(int i, int candies){
    if(candies >= k) return 0;

    int &ret = memo[i][candies];
    if(~ret) return ret;

    ret = OO;
    for (int j = 0; j < n; ++j)
        if(a[j] > a[i] && color[i] != color[j])
            ret = min(ret, abs(i - j) + dp(j, a[j] + candies));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.precision(9);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n >> s >> k, s--;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> color;

    memset(memo, -1, sizeof memo);

    ans = OO;
    for (int i = 0; i < n; ++i)
        ans = min(ans, abs(s - i) + dp(i, a[i]));

    cout << (ans == OO ? -1 : ans);

    return 0;
}

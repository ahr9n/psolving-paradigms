#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 2E5 + 5, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;;
int t, c, memo[701][201][51]; // handle + in states

int dp(int i, int n1, int n5, int n10) { // state compression
    if (i == c) return 0;

    int &ret = memo[n1][n5][n10]; // dimension compression
    if (~ret) return ret;

    ret = OO;
    if(n10 >= 1) ret = min(ret, 1 + dp(i + 1, n1 + 2, n5, n10 - 1));
    if(n5 >= 2) ret = min(ret, 2 + dp(i + 1, n1 + 2, n5 - 2, n10));
    if(n1 >= 8) ret = min(ret, 8 + dp(i + 1, n1 - 8, n5, n10));
    if(n1 >= 3 && n10 >= 1) ret = min(ret, 4 + dp(i + 1, n1 - 3, n5 + 1, n10 - 1));
    if(n1 >= 3 && n5 >= 1) ret = min(ret, 4 + dp(i + 1, n1 - 3, n5 - 1, n10));

    return ret;
}

int n1, n5, n10;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> t;

    while (t--) {
        cin >> c >> n1 >> n5 >> n10;
        
        memset(memo, -1, sizeof memo);
        cout << dp(0, n1, n5, n10) << '\n';
    }

    return 0;
}

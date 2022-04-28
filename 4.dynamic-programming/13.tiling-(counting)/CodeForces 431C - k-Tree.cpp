#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 105, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
int sum, k, least, memo[N][2];

int dp(int i, bool taken){
    if(i == 0) return taken;
    
    int &ret = memo[i][taken];
    if(~ret) return ret;
    
    ret = 0;
    for (int j = 1; j <= k; ++j) {
        if(j > i) break;
        ret += dp(i - j, taken | (j >= least));
        if(ret >= MOD) ret -= MOD;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> sum >> k >> least;
    memset(memo, -1, sizeof memo);
    cout << dp(sum, 0);

    return 0;
}

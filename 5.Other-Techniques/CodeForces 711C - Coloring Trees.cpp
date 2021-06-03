#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

const int N = 101;
const ll OO = 0x3f3f3f3f3f3f3f3f;

int trees, colors, neededBeauty;
ll color[N], litre[N][N], memo[N][N][N];

ll dp(int i, int prevColor, int beauty){
    if(i == trees) return (beauty == neededBeauty ? 0 : OO);

    ll &ret = memo[i][prevColor][beauty];
    if(~ret) return ret;

    ret = OO;
    if(color[i]) ret = dp(i+1, color[i], beauty + (color[i] != prevColor));
    else for (int j = 1; j <= colors; ++j)
        ret = min(ret, litre[i][j-1] + dp(i+1, j, beauty + (j != prevColor)));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> trees >> colors >> neededBeauty;
    for (int i = 0; i < trees; ++i)
        cin >> color[i];

    for (int i = 0; i < trees; ++i)
        for (int j = 0; j < colors; ++j)
            cin >> litre[i][j];

    memset(memo, -1, sizeof memo);
    cout << (dp(0, 0, 0) >= OO ? -1 : dp(0, 0, 0));
    
    return 0;
}

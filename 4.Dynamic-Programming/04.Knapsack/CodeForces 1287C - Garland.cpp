#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 105, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
ll n, p[N], mem[N][N][N][2], e, o;

ll dp(int idx, int odd, int even, int prev){
    if(idx == n) return 0;

    ll &ret = mem[idx][odd][even][prev];
    if(~ret) return ret;

    if(p[idx]){
        ret = (prev != p[idx]%2) + dp(idx+1, odd, even, p[idx] % 2);
    }else{
        ll ch1 = 1e18, ch2 = 1e18;
        if(even > 0) ch1 = (prev != 0) + dp(idx+1, odd, even-1, 0);
        if(odd > 0) ch2 = (prev != 1) + dp(idx+1, odd-1, even, 1);
        ret = min(ch1, ch2);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n;
    vector<int> num(n+1, false);
    for (int i = 0; i < n; ++i)
        cin >> p[i], num[p[i]] = true;

    for (int i = 1; i <= n; ++i)
        if(!num[i]) (i%2 == 0 ? e : o)++;

    memset(mem, -1, sizeof mem);
    cout << min(dp(0, o, e, 1), dp(0, o, e, 0));

    return 0;
}

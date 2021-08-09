#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 11, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
ll a[N][2], mem[N][N], mini;
int n, t;

ll dp(int i, int j){
    if(i == j) return 0;

    if(~mem[i][j]) return mem[i][j];

    mem[i][j] = 1e15;
    for (int k = i; k < j; ++k)
        mem[i][j] = min(mem[i][j], dp(i, k) + dp(k+1, j) + (a[i][0]*a[k][1]*a[j][1]));

    return mem[i][j];
}

void build(int i, int j){
    if(i == j) return cout << "A" << i, void();

    ll ret = dp(i, j);

    cout << "(";
    for (int k = i; k < j; ++k)
        if(ret == dp(i, k) + dp(k+1, j) + (a[i][0]*a[k][1]*a[j][1])) {
            build(i, k);
            cout << " x ";
            build(k + 1, j);
            break;
        }
    cout << ")";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    while(cin >> n, n){
        for (int i = 1; i <= n; ++i)
            cin >> a[i][0] >> a[i][1];

        memset(mem, -1, sizeof mem);
//        mini = dp(1, n);

        cout << "Case " << ++t << ": ";
        build(1, n);
        cout << '\n';
    }

    return 0;
}

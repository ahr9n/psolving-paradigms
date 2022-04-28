#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 55, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
int a[N], mem[N][N];
int n;

int dp(int i, int j, int s = 1, int e = n){
    if(i == j || s > e) return 0;

    if(~mem[s][e]) return mem[s][e];

    mem[s][e] = 1e7;
    for (int k = s; k <= e; ++k)
        mem[s][e] = min(mem[s][e], dp(i, a[k], s, k-1)+dp(a[k]+1, j, k+1, e)+(j-i+1));

    return mem[s][e];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    int k;
    while(cin >> k, k) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        memset(mem, -1, sizeof mem);

        cout << "The minimum cutting is " << dp(1, k) << ".\n";
    }
    return 0;
}

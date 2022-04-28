#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 101, M = 301, MOD = 1E9 + 7, OO = 0x3f3f3f3f;;
int n, food, ton[N], mem[N][N * M];

int dp(int i, int all){
    if(all < 0) return -1e7;
    if(i == n) return 0;

    int &ret = mem[i][all];
    if(~ret) return ret;

    return ret = max(dp(i+1, all), 1 + dp(i+1, all - (n-i) * ton[i]));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.precision(9);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> food;
    for (int i = 0; i < n; ++i)
        cin >> ton[i];

    memset(mem, -1, sizeof mem);
    cout << dp(0, food);

    return 0;
}

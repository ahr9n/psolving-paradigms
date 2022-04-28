#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

const int N = 102, M = N, MOD = 1E9 + 7, OO = 0x3f3f3f3f;;
int n, sum[N][N], now, maxSum;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.precision(9);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    while (cin >> n) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> sum[i][j];

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                sum[i][j] += sum[i-1][j] + sum[i][j-1]; // add top and left
                sum[i][j] -= sum[i-1][j-1]; // avoid double count
            } // inclusion-exclusion principle

        maxSum = -127*100*100; // lowest possible for this problem
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)  // start
            for (int k = i; k <= n; ++k) for (int l = j; l <= n; ++l) { // end
                now = sum[k][l];
                now -= sum[i-1][l];
                now -= sum[k][j-1];
                now += sum[i-1][j-1];
                maxSum = max(maxSum, now);
            }

        cout << maxSum << '\n';
    }

    return 0;
}

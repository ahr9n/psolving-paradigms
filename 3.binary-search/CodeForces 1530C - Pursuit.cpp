#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 2E5 + 5, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
int t, n;
ll a[N], b[N], l, r, mid, ans, all, s1, s2;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        sort(a+1, a + n+1); reverse(a+1, a + n+1);
        sort(b+1, b + n+1); reverse(b+1, b + n+1);

        for (int i = 1; i <= n; ++i)
            a[i] += a[i - 1], b[i] += b[i - 1];

        l = ans = 0, r = 2e5;
        while (l <= r) {
            mid = (l + r) / 2;
            all = (mid + n) - (mid + n) / 4;
            s1 = (all <= mid ? 100 * all : 100 * mid + a[all - mid]);
            s2 = (all <= n ? b[all] : b[n]);

            if (s1 >= s2) ans = mid, r = mid - 1;
            else l = mid + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}

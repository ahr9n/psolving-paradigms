#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {1, -1, 0,  0, -1, -1, -1,  1, 1, 1};
int dy[] = {0,  0, 1, -1, -1,  0,  1, -1, 0, 1};

const int N = 1e2+5;
int t, n, a[3*N], ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n, ans = 0;
        for (int i = 0; i < 3 * n; cin >> a[i++]);
        sort(a, a+(3*n));
        for (int i = 3*n - 2; i >= n; i -= 2) ans += a[i];
        cout << ans << '\n';
    }
    return 0;
}

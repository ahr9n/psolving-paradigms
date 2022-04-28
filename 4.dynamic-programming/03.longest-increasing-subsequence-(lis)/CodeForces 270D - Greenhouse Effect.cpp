#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2E5 + 5, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;;
int n, m, a[N], r;
double x;

int LIS(){
    vector<int> lst(n), rt(n);
    r = 0;

    for (int i = 0, idx; i < n; ++i) {
        idx = upper_bound(lst.begin(), lst.begin() + r, a[i]) - lst.begin();
        if(idx == r) ++r;
        rt[i] = idx + 1, lst[idx] = a[i];
    }
    return *max_element(rt.begin(), rt.end());
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.precision(9);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    /**
     * x <= lower_bound(x)
     * x <  upper_bound(x)
     */

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> x;

    cout << n - LIS();

    return 0;
}

#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 2E5 + 5, K = 21, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
int n, a;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    /**
     * x <= lower_bound(x)
     * x <  upper_bound(x)
     */

    cin >> n;
    set<int> st;
    for (int i = 0; i < n; ++i){
        cin >> a;
        auto it = st.lower_bound(a);
        if(it != st.end()) st.erase(it);
        st.insert(a);
    }
    cout << st.size();

    return 0;
}

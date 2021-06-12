#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2E5 + 5, M = 2E6 + 10, MOD = 1E9 + 7;
int t, n, a[10][10], maxi, cur;
set<int> r, c, d1, d2;

void solve(int i){
    // base case
    if(i == 8) maxi = max(maxi, cur);

    for (int j = 0; j < 8; ++j) {
        if(!r.count(i) && !c.count(j) && !d1.count(i+j) && !d2.count(i-j)){
            r.insert(i), c.insert(j), d1.insert(i+j), d2.insert(i-j);
            cur += a[i][j];
            solve(i+1);
            r.erase(i), c.erase(j), d1.erase(i+j), d2.erase(i-j);
            cur -= a[i][j];
        }
    }
}

void init(){
    r.clear(), c.clear(), d1.clear(), d2.clear();
    maxi = 0, cur = 0;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> t;
    while (t--) {
        init();

        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                cin >> a[i][j];

        solve(0);
        cout << maxi << '\n';
    }
    return 0;
}

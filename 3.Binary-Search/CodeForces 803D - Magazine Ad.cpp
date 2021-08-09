#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 1E5 + 5, M = 1E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;

int k, l, r, mid, ans, cnt, pos, str;
string s, t;

bool can(int x){

    cnt = 0, pos = -1, str = 1;
    for (int i = 0; s[i]; ++i){
        ++cnt;
        if (cnt > x){
            if (i - pos > x) return false;
            cnt = i - pos, ++str;
        }
        if (s[i] == ' ' || s[i] == '-') pos = i;
    }

    return (str <= k);
}

void solve(){

    l = 1, r = M;
    while (l <= r){
        mid = (l + r) / 2;
        if (can(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> k;
    while (cin >> t) s += t + " ";
    s.pop_back();
    solve();

    return 0;
}

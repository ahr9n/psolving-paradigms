#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 105, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
int n, mem[N][N*20];
vector<pair<pair<int, int>, pair<int, int>>> a;

int dp(int idx, int now){
    if(idx == n) return 0;

    int &ret = mem[idx][now];
    if(~ret) return ret;

    ret = dp(idx+1, now);
    if(a[idx].first.second + now >= a[idx].first.first) return ret;
    ret = max(ret, a[idx].second.first + dp(idx+1, now + a[idx].first.second));

    return ret;
}

vector<int> items;
void build(int idx, int now){
    if(idx == n) return;


    if(mem[idx][now] == dp(idx+1, now)){
        build(idx+1, now);
    }else if(a[idx].first.second + now < a[idx].first.first
            && mem[idx][now] == a[idx].second.first + dp(idx+1, now + a[idx].first.second)){
        items.push_back(a[idx].second.second);

        build(idx+1, now + a[idx].first.second);
    }
}

ll t, d, p;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t >> d >> p;
        a.push_back({{d, t}, {p, i+1}});
    }
    sort(a.begin(), a.end());

    memset(mem, -1, sizeof mem);
    cout << dp(0, 0) << '\n';

    build(0, 0);
    cout << items.size() << '\n';
    for(auto& it:items) cout << it << ' ';

    return 0;
}

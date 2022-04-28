#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

using namespace std;

#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define Unique(a)        a.erase(unique(inc(a)), a.end())
#define what_is(x)       cerr << #x << " is " << x << '\n';

using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0,  1, -1,  0, 1, -1, 0};
int dy[] = {0,  0, 0, -1, -1, -1, 1,  1, 1};

const int N = 105, M = 1E6+5, MOD = 1E9+7;
int n, m, s[N], d[N], c[N];
int rest[N], prep[N], exam[N], ans[N];
map<int, tuple<int, int, int>> theDay;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        cin >> s[i] >> d[i] >> c[i];
        ans[d[i]] = m+1;
        theDay[d[i]] = {s[i], c[i], i+1};
    }

    for(auto &it:theDay){
        int k = 0;
        for(int i=get<0>(it.second); i<it.first && k<get<1>(it.second); ++i)
            if(!ans[i]) ans[i] = get<2>(it.second), k++;
        if(k != get<1>(it.second)) return cout << -1, 0;
    }

    for(int i=1; i<=n; ++i)
        cout << ans[i] << " \n"[i == n];

    return 0;
}

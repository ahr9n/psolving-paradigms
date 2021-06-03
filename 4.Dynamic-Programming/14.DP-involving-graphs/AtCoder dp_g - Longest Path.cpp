#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 2e5 + 5, M = 1e6 + 5, OO = 0x3f3f3f3f;
int n, m, ne, head[N], nxt[M], to[M], memo[N];

void init(){
    memset(head, -1, n*sizeof head[0]);
    ne = 0;
}

void addEdge(int f, int t){
    nxt[ne] = head[f];
    to[ne] = t;
    head[f] = ne++;
}

int dp(int u){
    int &ret = memo[u];
    if(~ret) return ret;

    for(int k=head[u]; ~k; k=nxt[k])
        ret = max(ret, 1 + dp(to[k]));

    return ret;
}

int u, v, ans;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n >> m, init();
    while (m--){
        cin >> u >> v;
        addEdge(u-1,v-1);
    }

    memset(memo, -1, sizeof memo);
    for (int i = 0; i < n; ++i)
        ans = max(ans, dp(i));

    cout << ++ans;

    return 0;
}

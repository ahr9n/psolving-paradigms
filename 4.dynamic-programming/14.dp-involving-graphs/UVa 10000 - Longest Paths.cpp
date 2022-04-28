#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {1, -1, 0,   0};
int dy[] = {0,  0, 1,  -1};

const int N = 2e2 + 5, M = 5e4 + 4, OO = 0x3f3f3f3f;
int n, t, m, ne, head[N], nxt[M], to[M], memo[N], ans[N];

void init(){
    memset(head, -1, sizeof head);
    memset(memo, -1, sizeof memo);
    memset(ans,   0, sizeof ans);
    ne = 0;
}

void addEdge(int f, int t){
    nxt[ne] = head[f];
    to[ne] = t;
    head[f] = ne++;
}

int start;
int dfs(int u){
    if(~memo[u]) return memo[u];

    int ret = 0, v, now;
    ans[u] = u;

    for(int k=head[u]; ~k; k=nxt[k]) {
        v = to[k], now = dfs(v) + 1;
        if (ret == now)
            ans[u] = min(ans[v], ans[u]);
        if (ret < now)
            ret = now, ans[u] = ans[v];
    }

    memo[u] = ret;
    return memo[u];
}

int u, v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    t = 0;
    while (cin >> n, n){
        init();
        cin >> start;
        while (cin >> u >> v, (u + v))
            addEdge(u-1, v-1);

        cout << "Case " << ++t << ": The longest path from " << start
             << " has length " << dfs(start-1) << ", finishing at " << ans[start-1]+1 << ".\n\n";
    }

    return 0;
}

#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int n, m, maxi;
string s;
vector<vector<int>> adjList;
vector<int> vis;

bool cycle = false;
void dfs(int u){
    vis[u] = 1;
    for(auto& v:adjList[u])
        if(vis[v] == 0) dfs(v);
        else if(vis[v] == 1) return cycle = true, void();
    vis[u] = 2;
}

int memo[(int)3e5 + 5][27];
int dp(int u, int ch){
    int &ret = memo[u][ch];
    if(~ret) return ret;

    int now = (ch == s[u] - 'a');
    ret = now;
    for (auto& v:adjList[u])
        ret = max(ret, dp(v, ch) + now);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n >> m >> s;
    adjList = vector<vector<int>> (n);
    vis.resize(n);

    while (m--){
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);
    }
    for (int i = 0; i < n; ++i)
        if(!vis[i]) dfs(i);
    if(cycle) return cout << -1, 0;

    memset(memo, -1, sizeof memo);
    for (int i = 0; i < n; ++i)
        for (int ch = 0; ch < 27; ++ch)
            maxi = max(maxi, dp(i, ch));

    cout << maxi;
    return 0;
}

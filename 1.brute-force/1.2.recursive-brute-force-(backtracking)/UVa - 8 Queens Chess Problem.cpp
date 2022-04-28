#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2E5 + 5, M = 2E6 + 10, MOD = 1E9 + 7;
int t, x, y, test, cnt;
bool vis[3][20];
vector<int> grid;

void solve(int i){
    // base case
    if(i > 8){
        cout << " " << cnt++ << "      "; // 1 + 6 spaces
        for (int j = 0; j < 8; ++j)
            cout << grid[j] << " \n"[j == 7];
        return;
    }

    if(i == y){
        grid.push_back(x);
        solve(i+1);
        grid.pop_back();
    }else {
        for (int j = 1; j <= 8; ++j)
            if (!vis[0][j] && !vis[1][j+i] && !vis[2][j+8-i]) {
                vis[0][j] = vis[1][j+i] = vis[2][j+8-i] = 1;
                grid.push_back(j);
                solve(i+1);
                vis[0][j] = vis[1][j+i] = vis[2][j+8-i] = 0;
                grid.pop_back();
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> t;
    for(test = 1; test <= t; ++test) {
        cin >> x >> y;

        cout << "SOLN       COLUMN\n"; // 7 spaces
        cout << " #      1 2 3 4 5 6 7 8\n\n";

        memset(vis, false, sizeof vis);
        vis[0][x] = vis[1][x+y] = vis[2][x+8-y] = 1, cnt = 1;

        solve(1);
        if(test != t) cout << '\n';
    }

    return 0;
}

#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;

const int N = 200, M = N, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
int n, valid, vid;
int row[N][N], col[N][N], box[N][N], vis[N], grid[N][N];

void backtrack(int now) {
    if (valid == 1) return;
    if (now > n * n * n * n){
        for (int i = 1; i <= n * n; ++i)
            for (int j = 1; j <= n * n; ++j)
                cout << grid[i][j] << " \n"[j == n * n];
        return valid = 1, void();
    }

    if (vis[now]) backtrack(now + 1);
    else {
        int r = (now - 1) / (n * n) + 1;
        int c = now % (n * n);
        if (c == 0) c = n * n;

        for (int j = 1; j <= n * n; ++j) {
            int idx = ((r - 1) / n) * n + ((c - 1) / n) + 1;
            if (!col[c][j] && !row[r][j] && !box[idx][j]) {
                row[r][j] = col[c][j] = box[idx][j] = vis[now] = 1, grid[r][c] = j;
                backtrack(now + 1);
                row[r][j] = col[c][j] = box[idx][j] = vis[now] = grid[r][c] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    while (cin >> n) {
        if (vid) cout << '\n';
        ++vid, valid = 0;

        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(box, 0, sizeof box);
        memset(vis, 0, sizeof vis);

        for (int i = 1, cnt = 0; i <= n * n; ++i)
            for (int j = 1; j <= n * n; ++j) {
                cin >> grid[i][j];
                row[i][grid[i][j]] = col[j][grid[i][j]] = 1;
                int idx = ((i - 1) / n) * n + ((j - 1) / n) + 1;
                box[idx][grid[i][j]] = 1;

                ++cnt;
                if (grid[i][j]) vis[cnt] = 1;
            }

        if(n == 1){
            cout << (grid[1][1] <= 1 ? "1" : "NO SOLUTION") << '\n';
        }else {
            backtrack(1);
            if(!valid) cout << "NO SOLUTION\n";
        }
    }

    return 0;
}

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

int n;


void solve(int i, vector<string> grid, int rem, vector<int> r, vector<int> c, vector<int> d1, vector<int> d2){
    if (rem == 0) {
        for (int j = 0; j < n; ++j)
            cout << grid[j] << '\n';
        cout << '\n';
        return;
    }

    for (int j = 0; j < n; ++j) {
        if(grid[i][j] == '.' && !c[j] && !d1[i+j] && !d2[i-j+21]) {
            c[j] = d1[i+j] = d2[i-j+21] = 1, grid[i][j] = 'Q';
            solve(i+1, grid, rem-1, r, c, d1, d2);
            c[j] = d1[i+j] = d2[i-j+21] = 0, grid[i][j] = '.';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<string> grid(n, string(n, '.'));
    vector<int> v(45);
    solve(0, grid, n, v, v, v, v);

    return 0;
}

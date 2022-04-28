#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2E5 + 5, M = 2E6 + 10, MOD = 1E9 + 7;
int t, n, a[N];

bool vis[10];
vector<vector<int>> st;

void solve(int i, vector<int> v){
    /// base case
    if(i == n){
        st.push_back(v);
        return;
    }

    /// code :: do something
    for (int j = 1; j <= n; ++j) {
        if(vis[j]) continue;;

        vis[j] = 1;
        v.push_back(j);
        solve(i+1, v);
        v.pop_back();
        vis[j] = 0;
    }

    /// return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    solve(0, {});

    for(int i=0; i<st.size(); ++i)
        for(int j=0; j<st[i].size(); ++j)
            cout << st[i][j] << " \n"[j == st[i].size() -1];


    return 0;
}

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

const int N = 15, M = 2E6 + 10, MOD = 1E9 + 7;
int n, m, a[N][N];

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

multiset<vector<int>> st;

vector<int> v;
bool valid(int i, int j){
    return (i<n && i>=0 && j<m && j>=0);
}

void sol(int i, int j){
    if(i == n-1 && j == m-1){
        st.insert(v);
        return;
    }
    if(!valid(i, j)) return;

    v.push_back(a[i+1][j]);
    sol(i+1, j);
    v.pop_back();

    v.push_back(a[i][j+1]);
    sol(i, j+1);
    v.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    v.push_back(a[0][0]);
    sol(0, 0);
    for(auto &it:st){
        for(auto &is:it) cout << is << ' ';
        cout << '\n';
    }

    return 0;
}

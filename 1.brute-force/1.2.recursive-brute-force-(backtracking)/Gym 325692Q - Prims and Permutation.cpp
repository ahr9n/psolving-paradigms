#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1E5 + 5, M = 2E6 + 10, MOD = 1E9 + 7;
int t, n, vis[20];

bool isPrime(int x){
    if(x == 1) return false;
    for(int i=2; i*i<=x; ++i)
        if(x % i == 0) return false;
    return true;
}

vector<int> perm;
set<vector<int>> st;

void solve(int i){
    if(i == n){
        if(isPrime(perm.front() + perm.back()))
            st.insert(perm);
        return;
    }

    for (int j = 2; j <= n; ++j){
        if(vis[j]) continue;
        if(!isPrime(perm.back() + j)) continue;

        vis[j] = true;
        perm.push_back(j);
        solve(i+1);
        vis[j] = false;
        perm.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    perm.push_back(1);
    vis[1] = true;

    solve(1);

    for(auto &it:st){
        for(auto &is:it) cout << is << ' ';
        cout << '\n';
    }

    return 0;
}

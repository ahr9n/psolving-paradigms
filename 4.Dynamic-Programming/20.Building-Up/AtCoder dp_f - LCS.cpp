#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 3E3 + 5, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
string s, t;

int memo[N][N];
int LCS(int i, int j){
    if(i == s.size() || j == t.size()) return 0;

    int &ret = memo[i][j];
    if(~ret) return ret;

    ret = 0;
    if(s[i] == t[j]) ret = max(ret, 1 + LCS(i+1, j+1));
    return ret = max({ret, LCS(i, j+1), LCS(i+1, j)});
}
void build(int i, int j){
    if(i == s.size() || j == t.size()) return;

    int ret = LCS(i, j);
    if(s[i] == t[j] && ret == 1 + LCS(i+1, j+1)){
        cout << s[i];
        build(i+1, j+1);
    }else if(ret == LCS(i, j+1)) build(i, j+1);
    else build(i+1, j);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> s >> t;

    memset(memo, -1, sizeof memo);
    build(0, 0);

    return 0;
}

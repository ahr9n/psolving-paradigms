#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 1e3 + 5, M = 2e6 + 10, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
string s, t;
int mem[N][N], vis[N][N], n, vid;

int dp(int i, int j){
    if(i > j) return 0;
    if(i == j) return 1;

    int &ret = mem[i][j];
    if(vis[i][j] == vid) return ret;
    vis[i][j] = vid;

    ret = 0;
    if(s[i] == s[j]) ret = 2 + dp(i+1, j-1);
    else ret = max(dp(i+1, j), dp(i, j-1));

    return ret;
}

string rt[N][N];
int memB[N][N];

string build(int i, int j){
    if(i > j) return "";

    string &ret = rt[i][j];
    if(memB[i][j] == vid) return ret;
    memB[i][j] = vid;

    ret.clear();

    if(s[i] == s[j]) return ret = s[i] + build(i+1, j-1);

    int ch2 = mem[i+1][j], ch3 = mem[i][j-1];

    if(ch2 == ch3) ret = min(build(i+1, j), build(i, j-1));
    else if(ch3 == mem[i][j]) ret = build(i, j-1);
    else ret = build(i+1, j);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    while (cin >> s) {
        memset(mem, -1, sizeof mem);
        vid++, n = dp(0, s.size() - 1);

        cout << (t = build(0, s.size() - 1));
        reverse(t.begin(), t.end());
        cout << (n & 1 ? (t.size() == 1 ? "" : t.substr(1, n-1)) : t) << '\n';
    }

    return 0;
}

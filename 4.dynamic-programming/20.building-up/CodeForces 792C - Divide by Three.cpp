#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 2e5+5, M = 1E5 + 5, MOD = 1E9 + 7, OO = 0x3f3f3f3f;;
int mem[N][3][2];
string n;

int dp(int i, int remSum, bool dig){
    if(i == n.size()) return (!remSum && dig ? 0 : OO);

    int &ret = mem[i][remSum][dig];
    if(~ret) return ret;

    ret = 1 + dp(i+1, remSum, dig);
    if(n[i] != '0' || dig)
        ret = min(ret, dp(i+1, (remSum+n[i]-'0')%3, 1));

    return ret;
}

void build(int i, int remSum, bool dig){
    if(i == n.size()) return;

    int ret = mem[i][remSum][dig], ch = OO;
    if(n[i] != '0' || dig)
        ch = dp(i+1, (remSum+n[i]-'0')%3, 1);

    if(ret == ch) cout << n[i], build(i+1, (remSum+n[i]-'0')%3, 1);
    else build(i+1, remSum, dig);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n;
    memset(mem, -1, sizeof mem);

    if(dp(0, 0, 0) >= OO)
        return cout << (count(n.begin(), n.end(), '0') ? 0 : -1), 0;

    build(0, 0, 0);

    return 0;
}

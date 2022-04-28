#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 1E5 + 5, M = 2E6 + 10, MOD = 1E9 + 7, OO = 0x3f3f3f3f;
int n, mem[N][13];
string s;

int dp(int i, int rem){
    if(i == n) return rem == 5;

    int &ret = mem[i][rem];
    if(~ret) return ret;

    ret = 0;
    if(s[i] == '?')
        for (int j = 0; j < 10; ++j)
            (ret += dp(i+1, (rem*10 + j)%13) %MOD) %= MOD;
    else
        (ret += dp(i+1, (rem*10 + s[i]-'0')%13) %MOD) %= MOD;

    return ret %= MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> s, n = s.size();
    memset(mem, -1 ,sizeof mem);
    cout << dp(0, 0);

    return 0;
}

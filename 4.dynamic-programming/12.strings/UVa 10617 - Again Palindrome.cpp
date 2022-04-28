#include <bits/stdc++.h>

using namespace std;

string s;
long long test, n, dp[65][65];

long long gen(int i, int j){
    if(i>j) return 0;
    if(i==j) return 1;

    long long &ret = dp[i][j];
    if(~ret) return ret;

    if(s[i]==s[j]) return ret = 1 + gen(i, j-1) + gen(i+1, j);
    else return ret = gen(i, j-1) + gen(i+1, j) - gen(i+1, j-1);
}

int main()
{
    cin >> test;
    while(test--){
        cin >> s, n = s.size();

        memset(dp, -1, sizeof dp);
        cout << gen(0, n-1) << '\n';
    }
    return 0;
}

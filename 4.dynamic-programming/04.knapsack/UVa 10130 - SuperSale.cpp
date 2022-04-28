#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1005, M = 35;
int t, n, g, mw, pw[N][2], dp[N][M], maxi;
int sol(int i, int MAX){
    if(i==n || MAX<1) return 0;

    int &ret = dp[i][MAX];
    if(~ret) return ret;

    int path1 = sol(i+1, MAX), path2 = 0;
    if(MAX>=pw[i][1])
        path2 = pw[i][0] + sol(i+1, MAX-pw[i][1]);

    return ret = max(path1, path2);
}

int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> pw[i][0] >> pw[i][1];

        memset(dp, -1, sizeof dp);
        cin >> g, maxi = 0;
        while(g--)
            cin >> mw, maxi += sol(0, mw);
        cout << maxi << "\n";
    }

    return 0;
}

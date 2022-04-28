#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;
int n, abc[N][3], dp[N][3];

int sol(int i, int ch){
    if(i==n-1) return abc[i][ch];

    int &ret = dp[i][ch];
    if(~ret) return ret;

    return ret = max(abc[i][ch]+sol(i+1, (ch+1)%3), abc[i][ch]+sol(i+1, (ch+2)%3));
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> abc[i][0] >> abc[i][1] >> abc[i][2];

    memset(dp, -1, sizeof dp);
    cout << max({sol(0, 0), sol(0, 1), sol(0, 2)});
}

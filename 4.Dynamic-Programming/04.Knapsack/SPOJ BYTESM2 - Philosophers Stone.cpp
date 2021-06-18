#include <bits/stdc++.h>

using namespace std;

int t, r, c, arr[101][101], dp[101][101];

bool valid(int x, int y){
    return (x<r && y<c);
}
int sol(int i, int j){
    if(i==r || j==c || j<0) return 0;
    if(i==r-1) return arr[i][j];

    int &ret = dp[i][j];
    if(~ret) return ret;

    return ret = arr[i][j] + max({sol(i+1, j), sol(i+1, j+1), sol(i+1, j-1)});
}

int main()
{
    cin >> t;
    while(t--){
        cin >> r >> c;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                cin >> arr[i][j];

        memset(dp, -1, sizeof dp);

        int maxi = 0;
        for(int i=0; i<c; i++)
            maxi = max(sol(0, i), maxi);
        cout << maxi << '\n';
    }

    return 0;
}

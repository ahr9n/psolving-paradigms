#include <bits/stdc++.h>

using namespace std;

int t, p, q, r, c, dp[104][104];
bool vis[104][104], sad;
string s;

bool valid(int x, int y){
    return (x<r && y<c && !vis[x][y]);
}

int solve(int x, int y){
    if(x==r-1 && y==c-1) return 1;

    int &ret = dp[x][y];
    if(~ret) return ret;

    ret = 0;
    if(valid(x, y+1)) ret += solve(x, y+1);
    if(valid(x+1, y)) ret += solve(x+1, y);

    return ret;
}

int main(){

    sad = false;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &r, &c);
        memset(dp, -1, sizeof dp);
        memset(vis, false, sizeof vis);

        getline(cin, s);
        for(int i=0; i<r; i++){
            getline(cin, s);

            stringstream scan(s);
            scan >> p;
            while(scan >> q) vis[p-1][q-1] = true;
        }

        if(sad) cout << '\n';
        cout << solve(0, 0) << '\n', sad = true;
    }
}

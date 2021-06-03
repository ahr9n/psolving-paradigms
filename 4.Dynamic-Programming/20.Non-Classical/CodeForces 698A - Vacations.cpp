#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, arr[101], dp[101][2][2];
int sol(int i, int gym, int contest){
    if(i==n) return 0;

    int &ret = dp[i][gym][contest];
    if(~ret) return ret;

    if(!arr[i]){
        ret = 1 + sol(i+1, 0, 0);
    }else if(arr[i] == 1){
        if(!contest) ret = min(sol(i+1, 0, 1), 1 + sol(i+1, 0, contest));
        else ret = 1 + sol(i+1, 0, 0);
    }else if(arr[i] == 2){
        if(!gym) ret = min(sol(i+1, 1, 0), 1 + sol(i+1, gym, 0));
        else ret = 1 + sol(i+1, 0, 0);
    }else if(arr[i] == 3){
        if(gym && contest) ret = 1 + sol(i+1, 0, 0);
        else if(gym) ret = min(sol(i+1, 0, 1), 1 + sol(i+1, 0, 0));
        else if(contest) ret = min(sol(i+1, 1, 0), 1 + sol(i+1, 0, 0));
        else ret = min({sol(i+1, 0, 1), sol(i+1, 1, 0), 1+sol(i+1, gym, contest)});
    }

    return ret;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof dp);
    cout << sol(0, 0, 0);
    return 0;
}

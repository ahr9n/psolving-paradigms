#include <bits/stdc++.h>

using namespace std;

int t, n;
int arr[101], dp[101][50005];

int sol(int i, int diff){
    if(i==n) return diff;

    int &ret = dp[i][diff];
    if(~ret) return ret;

    return ret = min(sol(i+1, diff+arr[i]), sol(i+1, abs(arr[i]-diff)));
}

int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> arr[i];

        memset(dp, -1, sizeof dp);
        cout << sol(0, 0) << '\n';
    }
    return 0;
}

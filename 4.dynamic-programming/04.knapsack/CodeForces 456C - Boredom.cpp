#include <bits/stdc++.h>

using namespace std;

#define all(a)      a.begin(), a.end()
#define Unique(n)   (n).erase(unique(all(n)), (n).end())

const int N = 1E5+7;
long long n, k, freq[N], dp[N];

long long sol(int i){
    if(~dp[i]) return dp[i];
    return dp[i] = max(freq[i]*i + sol(i+2), sol(i+1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> k, freq[k]++;

    memset(dp, -1, sizeof dp), dp[100002] = dp[100003] = 0;
    cout << sol(0);
    return 0;
}

/*  UntilDeathDoesUsApart
    DO   NOT   GIVE   UP!
*/

#include <bits/stdc++.h>

using namespace std;

#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define Unique(n)        (n).erase(unique(in(n)), (n).end())
#define to(i, a, n)      for(int i=a; i<n; i++)
#define fr(i, a, n)      for(int i=a; i>=n; i--)
#define read(arr, l, r)  for(int i=l; i<r; cin >> arr[i++])
#define prnt(arr, l, r)  for(int i=l; i<r; cout << arr[i++] << " \n"[i==r])

typedef long long ll;
typedef long double ld;

const int N = 1005;
int t, dp[N][N];
string s;

int sol(int i, int j){
    if(i > j) return 0;

    int &ret = dp[i][j];
    if(~ret) return ret;

    if(s[i] == s[j]) ret = sol(i+1, j-1);
    else{
        int path1 = sol(i+1, j-1), path2 = sol(i+1, j), path3 = sol(i, j-1);
        ret = 1 + min({path1, path2, path3});
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    to(i, 1, t+1){
        cin >> s;
        memset(dp, -1, sizeof dp);
        cout << "Case " << i << ": " << sol(0, s.size()-1) << '\n';
    }

    return 0;
}

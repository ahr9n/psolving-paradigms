#include <bits/stdc++.h>

using namespace std;

#define pi               acos(-1)
#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define Unique(n)        (n).erase(unique(inc(n)), (n).end())
#define what_is(x)       cerr << #x << " is " << x << '\n';
#define to(i, a, n)      for(int i=a; i<n; i++)
#define fr(i, a, n)      for(int i=a; i>=n; i--)
#define read(arr, l, r)  for(int i=l; i<r; cin >> arr[i++])
#define prnt(arr, l, r)  for(int i=l; i<r; cout << arr[i++] << " \n"[i==r])

typedef long long ll;
typedef long double ld;

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a[3], res = 0; cin >> n;
    to(i, 0, 3) cin >> a[i];

    auto check = [&](int x, int y, int z){
        /// a*x + b*y + c*z = n
        return (a[0]*x + a[1]*y + a[2]*z == n && 0 <= z && z <= 4000);
    };

    to(x, 0, min(n, 4000)+1) to(y, 0, min(n, 4000)+1){
        int z = (n - (x*a[0] + y*a[1])) / a[2];
        if(check(x, y, z)) res = max(res, x+y+z);
    }

    cout << res;
    return 0;
}

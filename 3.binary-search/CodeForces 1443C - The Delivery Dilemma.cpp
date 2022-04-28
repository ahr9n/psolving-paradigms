#include <bits/stdc++.h>

using namespace std;

#define pi               acos(-1)
#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define Unique(n)        (n).erase(unique(inc(n)), (n).end())
#define what_is(x)       cerr << #x << " is " << x << '\n';
#define to(i, a, n)      for(ll i=a; i<n; i++)
#define fr(i, a, n)      for(int i=a; i>=n; i--)
#define read(arr, l, r)  for(int i=l; i<r; cin >> arr[i++])
#define prnt(arr, l, r)  for(int i=l; i<r; cout << arr[i++] << " \n"[i==r])

typedef long long ll;
typedef long double ld;

void solve(){
    int n; cin >> n;
    int a[n], b[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    int l = 1, r = 1000000007, ans = 1000000007;
    while(l <= r){
        int mid = (l+r)/2, sum = 0;

        bool ok = true;
        for(int i=0; i<n && ok; i++){
            if(a[i] > mid){
                sum += b[i];
                if(sum > mid) ok = false;
            }
        }

        if(ok)
            ans = min(ans, mid), r = mid-1;
        else
            l = mid+1;
    }
    cout << ans << '\n';

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}

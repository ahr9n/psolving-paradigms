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

const int MOD = 1000000000;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<ll> a(n); read(a, 0, n);

    ll fib[201] = {1, 1};
    to(i, 2, 201) (fib[i] += fib[i-1]+fib[i-2]) %= MOD;

    while(m--){
        int t; cin >> t;
        if(t == 1){
            int x, v; cin >> x >> v;
            a[x-1] = v;
        }else{
            int l, r; cin >> l >> r;

            ll ans = 0;
            to(i, 0, r-l+1) (ans = (ans+fib[i]*a[i+l-1]) % MOD) %= MOD;

            cout << ans << '\n';
        }
    }

    return 0;
}

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

    ll n, m, koko, ans, cur, t=1;
    while(cin >> n, n){
        cout << "Case " << t++ << ":\n";
        vector<ll> a(n); read(a, 0, n);
        vector<ll> sum;
        to(i, 0, n) to(j, i+1, n) if(a[i]!=a[j])
            sum.push_back(a[i]+a[j]);
        sort(inc(sum)); Unique(sum);

        cin >> m;
        while(m--){
            cin >> koko, cur = 1E9;
            to(i, 0, sum.size()) if(abs(koko-sum[i]) <= cur)
                cur = abs(koko-sum[i]), ans = sum[i];
            cout << "Closest sum to " << koko << " is " << ans << ".\n";
        }
    }


    return 0;
}

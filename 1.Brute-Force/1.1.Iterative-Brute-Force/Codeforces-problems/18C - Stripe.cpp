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

    int n; cin >> n;
    int a[n], pre[n], stripes = 0;
    to(i, 0, n){
        cin >> a[i];
        (!i ? pre[i] = a[i] : pre[i] = pre[i-1] + a[i]);
    }

    to(i, 0, n-1) stripes += (pre[n-1] == 2*pre[i]);
    cout << stripes;

    return 0;
}

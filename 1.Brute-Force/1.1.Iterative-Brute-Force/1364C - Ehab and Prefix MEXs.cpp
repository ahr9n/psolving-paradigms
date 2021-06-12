/*  UntilDeathDoesUsApart
    DO   NOT   GIVE   UP!
*/

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

int n, c;
bool ok[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> a(n), b(n, -1);
    to(i, 0, n){
        cin >> a[i];
        if(i) if(a[i] != a[i-1])
            b[i] = a[i-1], ok[a[i-1]] = 1;
    }
    ok[a[n-1]] = 1, c = 0;
    to(i, 0, n) if(b[i] == -1){
        while(ok[c]) c++;
        b[i] = c, ok[c++] = 1;
    }
    prnt(b, 0, n);

    return 0;
}

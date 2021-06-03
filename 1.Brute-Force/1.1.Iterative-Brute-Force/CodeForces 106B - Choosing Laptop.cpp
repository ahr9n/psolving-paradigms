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
    int a[n][4], c, ok, mini = 1E9, ans;
    to(i, 0, n) to(j, 0, 4) cin >> a[i][j];

    to(i, 0, n){
        ok = 1;
        to(j, 0, n){
            c = 0;
            to(k, 0, 4) if(a[j][k] > a[i][k]) c++;
            if(c == 4) ok = 0;
        }
        if(ok && mini > a[i][3]) mini = a[i][3], ans = i+1;
    }
    cout << ans;

    return 0;
}

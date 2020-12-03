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

    int m, u, v; cin >> m;
    int a[5][5] = {{}};

    while(m--){
        cin >> u >> v, u--, v--;
        a[u][v] = a[v][u] = 1;
    }

    to(i, 0, 5) to(j, i+1, 5) to(k, j+1, 5)
        if(!(a[i][j] + a[j][k] + a[i][k])
           ||(a[i][j] & a[j][k] & a[i][k]))
            return cout << "WIN", 0;
    cout << "FAIL";

    return 0;
}

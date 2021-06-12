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

const int N = 7;
int a[N][N], vis[N][N], n, m;

bool valid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m && a[i][j] && !vis[i][j]);
}

int sol(int i, int j){
    if(!valid(i, j)) return 0;
    if(i==n-1 && j==m-1) return 1;
    
    vis[i][j] = 1;
    int paths = 0;
    to(k, 0, 4) paths += sol(i+dx[k], j+dy[k]);
    vis[i][j] = 0;
    
    return paths;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    to(i, 0, n) to(j, 0, m) cin >> a[i][j];

    cout << sol(0, 0);

    return 0;
}

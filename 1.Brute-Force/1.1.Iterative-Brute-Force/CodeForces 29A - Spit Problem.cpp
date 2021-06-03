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
    map<int, int> pos;

    int xd[n][2];
    to(i, 0, n) cin >> xd[i][0] >> xd[i][1], pos[xd[i][0]] = xd[i][0]+xd[i][1];

    to(i, 0, n)
        if(pos.count(pos[xd[i][0]])) if(xd[i][0] == pos[pos[xd[i][0]]])
            return cout << "YES", 0;
    cout << "NO";

    return 0;
}

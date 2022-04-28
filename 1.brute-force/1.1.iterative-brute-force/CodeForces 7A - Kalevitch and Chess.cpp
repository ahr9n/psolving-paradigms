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

    string s[8], w, b, t;
    w.assign(8, 'W');
    // b.assign(8, 'B');

    to(i, 0, 8) cin >> s[i];

    int ans = 0;
    to(i, 0, 8) if(count(inc(s[i]), 'B') == 8) s[i] = w, ans++;
    to(j, 0, 8){
        t.clear();
        to(i, 0, 8) t += s[i][j];
        if(count(inc(t), 'B')) ans++;
    }

    cout << ans;

    return 0;
}

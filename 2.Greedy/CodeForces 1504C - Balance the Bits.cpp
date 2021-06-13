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

const int N = 3E5+5;

string s, a, b;
int t, n, x, y, z, c, ok;

void solve(){
    x = y = z = c = ok = 0;
    for(int i=0; i<n; ++i) x += (s[i] == '1');
    if(x & 1) return cout << "NO\n", void();

    for(y=0; y<n; ++y){
        if(s[y] == '1') ++c;
        if(c == x/2) break;
    }

    a.clear(), b.clear();
    for(int i=0; i<n; ++i){
        if(s[i] == '1'){
            if(i <= y) a += "(", b += "(", ++z;
            else a += ")", b += ")", --z;
        }else{
            if(ok) a += ")", b += "(", ++z;
            else a += "(", b += ")", --z;
            ok = !ok;
        }
        if(z < 0) return cout << "NO\n", void();
    }
    cout << "YES\n" << a << '\n' << b << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> s;
        solve();
    }

    return 0;
}

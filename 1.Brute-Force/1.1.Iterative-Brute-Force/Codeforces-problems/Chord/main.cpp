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

    vector<string> v = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
    to(i, 12, 36) v.push_back(v[i-12]);

    string a, b, c; cin >> a >> b >> c;
    if(!count(inc(v), a) || !count(inc(v), b) || !count(inc(v), c))
        return cout << "strange", 0;

    auto check = [&](string a, string b, string c){
        int x, y, z;
        to(i, 0, 36) if(a == v[i]){ x = i; break; }
        to(i, x, 36) if(b == v[i]){ y = i; break; }
        to(i, y, 36) if(c == v[i]){ z = i; break; }
        if(y-x == 4 && z-y == 3 && z-x == 7) return 1;
        if(y-x == 3 && z-y == 4 && z-x == 7) return 2;
        return 0;
    };

    /// abc acb bac bca cab cba
    if(check(a, b, c))      cout << (check(a, b, c) == 1 ? "major" : "minor");
    else if(check(a, c, b)) cout << (check(a, c, b) == 1 ? "major" : "minor");
    else if(check(b, a, c)) cout << (check(b, a, c) == 1 ? "major" : "minor");
    else if(check(b, c, a)) cout << (check(b, c, a) == 1 ? "major" : "minor");
    else if(check(c, a, b)) cout << (check(c, a, b) == 1 ? "major" : "minor");
    else if(check(c, b, a)) cout << (check(c, b, a) == 1 ? "major" : "minor");
    else cout << "strange";

    return 0;
}

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

map<ll, bool> mp;
vector<ll> humble = {0}, spec = {11, 12, 13};

void give(ll num){
    if(num>2000000000 || mp[num]) return;
    humble.push_back(num), mp[num] = true;
    give(num*2), give(num*3), give(num*5), give(num*7);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    give(1);
    sort(inc(humble));

    vector<string> a(10, "th");
    a[1] = "st", a[2] = "nd", a[3] = "rd";
    while(cin >> n, n)
        cout << "The " << n << (count(inc(spec), n%100) ? "th" : a[n%10]) << " humble number is " << humble[n] << ".\n";

    return 0;
}

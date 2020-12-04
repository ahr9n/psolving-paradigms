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

vector<ll> lucky;

void give(ll n, int four, int seven){
    if(four+seven > 10) return;
    if(four == seven) lucky.push_back(n);

    give(n*10+4, four+1, seven);
    give(n*10+7, four, seven+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    give(0, 0, 0);
    sort(inc(lucky));

    int i;
    for(i=0; lucky[i]<n; i++);
    cout << lucky[i];
}

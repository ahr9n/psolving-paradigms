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
vector<ll> lucky = {4444444444};

void give(ll num){
    if(num>1000000000 || mp[num]) return;
    lucky.push_back(num), mp[num] = true;
    give(num*10 + 4), give(num*10 + 7);
}

int nxt(int x){
    to(i, 0, 1024) if(lucky[i] >= x) return i;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    give(0);
    // lucky.size() = 1024

    sort(inc(lucky));
    vector<ll> luckyNum = {0};
    to(i, 0, 1023) luckyNum.push_back(lucky[i+1]-lucky[i]);

    pair<int, int> l, r; cin >> l.first >> r.first;

    l.second = nxt(--l.first);
    r.second = nxt(r.first);

    ll aft = 0, rem = r.first, bef = 0;
    to(i, 0, r.second+1){
        if(rem <= luckyNum[i]) break;
        aft += min(rem, luckyNum[i]) * lucky[i];
        rem -= luckyNum[i];
    }
    aft += rem * lucky[r.second];


    rem = l.first;
    to(i, 0, l.second+1){
        if(rem <= luckyNum[i]) break;
        bef += min(rem, luckyNum[i]) * lucky[i];
        rem -= luckyNum[i];
    }
    bef += rem * lucky[l.second];


    cout << aft - bef;

    return 0;
}

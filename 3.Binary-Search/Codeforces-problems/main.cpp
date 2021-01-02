#include <bits/stdc++.h>

using namespace std;

#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define to(i, a, n)      for(int i=a; i<n; i++)
#define fr(i, a, n)      for(int i=a; i>=n; i--)
#define read(arr, l, r)  for(int i=l; i<r; cin >> arr[i++])
#define prnt(arr, l, r)  for(int i=l; i<r; cout << arr[i++] << " \n"[i==r-1])

typedef long long ll;
typedef long double ld;

int dx[] = {0, 1,  0, -1}; // this one is
int dy[] = {1, 0, -1,  0}; // on purpose :P

int n, m;
vector<ll> a, b;

bool isOk(ll mid, int l1 = 0, int l2 = 0){

    while(l1 < n){
        if(l2 == m) return false;
        if(abs(a[l1] - b[l2]) > mid) l1--, l2++;
        l1++;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    a.resize(n), b.resize(m);
    read(a, 0, n); read(b, 0, m);

    ll l = 0, r = 1E10, mid, ans;
    while(l <= r){
        mid = (l+r) >> 1;
        if(isOk(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }

    cout << ans;

    return 0;
}

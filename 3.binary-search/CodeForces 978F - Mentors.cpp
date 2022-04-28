#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

using namespace std;

#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define Unique(a)        a.erase(unique(inc(a)), a.end())
#define what_is(x)       cerr << #x << " is " << x << '\n';

using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0,  1, -1,  0, 1, -1, 0};
int dy[] = {0,  0, 0, -1, -1, -1, 1,  1, 1};

const int N = 2E5+5, M = 1E6+5, MOD = 1E9+7;
int n, k, a[N], b[N], l, r, mid, ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; ++i)
        cin >> a[i], b[i] = a[i];

    sort(b, b+n);
    map<pair<int, int>, int> mp;
    for(int i=0; i<n; ++i){
        l = ans = 0, r = n-1;
        while (l <= r){
            mid = (l+r)/2;
            if(b[mid] < a[i])
                ans = l = mid+1;
            else r = mid-1;
        }
        mp[{a[i], i}] = ans;
    }

    while (k--){
        cin >> l >> r;
        l--, r--;
        if(a[l] > a[r]) mp[{a[l], l}]--;
        else if(a[r] > a[l]) mp[{a[r], r}]--;
    }

    for(int i=0; i<n; ++i)
        cout << mp[{a[i], i}] << " \n"[i == n-1];

    return 0;
}

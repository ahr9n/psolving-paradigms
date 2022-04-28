#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {1, -1, 0,  0, -1, -1, -1,  1, 1, 1};
int dy[] = {0,  0, 1, -1, -1,  0,  1, -1, 0, 1};

const int N = 1e6+5, OO = 0x3f3f3f3f;
ll n, m, a, c, x[N], ans, l, r, mid;

bool ok(ll val){
    l = 1, r = n;
    while (l <= r){
        mid = (l+r)/2;
        if(x[mid] == val) return true;

        if(x[mid] > val) r = mid-1;
        else l = mid+1;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a >> c >> x[0];
    for(int i=1; i<=n; ++i)
        x[i] = (a * x[i-1] + c) % m;

    for(int i=1; i<=n; ++i) if(ok(x[i])) ans++;
    cout << ans;

    return 0;
}

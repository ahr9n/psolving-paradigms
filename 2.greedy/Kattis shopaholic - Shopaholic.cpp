#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {1, -1, 0,  0, -1, -1, -1,  1, 1, 1};
int dy[] = {0,  0, 1, -1, -1,  0,  1, -1, 0, 1};

const int N = 2e5+5;
ll n, a[N], ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; cin >> a[i++]);
    sort(a, a+n);
    for(int i=n-3; i>=0; i-=3) ans += a[i];
    cout << ans;

    return 0;
}

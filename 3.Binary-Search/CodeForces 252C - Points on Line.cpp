#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {1, -1, 0,  0, -1, -1, -1,  1, 1, 1};
int dy[] = {0,  0, 1, -1, -1,  0,  1, -1, 0, 1};

const ld EPS = 1E-10;
const int N = 1e5+5, OO = 0x3f3f3f3f;
ll n, d, a[N];
ll ans, l, r, mid, now;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;
    for(int i=0; i<n; cin >> a[i++]);

    for(int i=0; i<n; i++){
        l = i, r = n-1, now = -1;
        while (l <= r){
            mid = (l+r)/2;
            if(a[mid] <= a[i]+d)
                now = mid, l = mid+1;
            else r = mid-1;
        }
        if(~now && i+2 <= now)
            ans += (now-i-1)*(now-i)/2;
    }
    cout << ans << '\n';


    return 0;
}

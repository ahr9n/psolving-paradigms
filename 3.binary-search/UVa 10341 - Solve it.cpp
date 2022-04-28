#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {1, -1, 0,  0, -1, -1, -1,  1, 1, 1};
int dy[] = {0,  0, 1, -1, -1,  0,  1, -1, 0, 1};

const ld EPS = 1E-10;
const int N = 1e6+5, OO = 0x3f3f3f3f;
ld p, q, r, s, t, u, lef, rig, mid, ans;

ld get(ld x){
    return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

ld bs() {
    lef = 0.0, rig = 1.0;
    while (lef <= rig) {
        mid = (lef + rig) / 2.0;
        if (get(mid) > 0.0)
            ans = mid, lef = mid+EPS;
        else rig = mid-EPS;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> p >> q >> r >> s >> t >> u){
        if(get(0.0) * get(1.0) > 0.0) cout << "No solution\n";
        else if(get(0.0) == 0.0) cout << fixed << setprecision(4) << 0.0 << '\n';
        else if(get(1.0) == 0.0) cout << fixed << setprecision(4) << 1.0 << '\n';
        else cout << fixed << setprecision(4) << bs() << '\n';
    }

    return 0;
}

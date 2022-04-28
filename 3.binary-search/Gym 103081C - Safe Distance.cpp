#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1005;
const ld EPS = 1e-7;

struct point {
    ld x, y;
};

struct DSU {
    int par[N], sz[N], cnt;

    void init(int n) {
        iota(par, par + n, 0);
        fill(sz, sz + n, 1);
        cnt = n;
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;

        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
} dsu;

vector<point> p;
ld x, y, l, r, mid, dx, dy;
int n;

void merge(ld mid) {
    dsu.init(n + 2);

    for (int i = 0; i < n; ++i) {
        if (p[i].x <= mid || p[i].y + mid >= y) dsu.merge(i, n);
        if (p[i].x + mid >= x || p[i].y <= mid) dsu.merge(i, n + 1);
    }
}

bool ok() {
    if(dsu.find(n) == dsu.find(n + 1)) // overlapping set of circles exceeding borders
        return false;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            if (dsu.find(i) == dsu.find(j)) continue;

            dx = p[j].x - p[i].x;
            dy = p[j].y - p[i].y;

            if (dx * dx + dy * dy <= (2 * mid) * (2 * mid)) {
                dsu.merge(i, j);
                if (dsu.find(n) == dsu.find(n + 1)) return false;
            }
        }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/
    cout << fixed << setprecision(7);

    cin >> x >> y >> n;
    p.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;

    l = 0.0, r = sqrt(x * x + y * y);
    while (l + EPS < r && (r + l) * EPS < (r - l)) {

        mid = (l + r) / 2;

        merge(mid);
        if (ok())
            l = mid;
        else
            r = mid;

    }
    cout << (l + r) / 2.0 << '\n';

    return 0;
}

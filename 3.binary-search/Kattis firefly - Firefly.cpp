#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {1, -1, 0,  0, -1, -1, -1,  1, 1, 1};
int dy[] = {0,  0, 1, -1, -1,  0,  1, -1, 0, 1};

const int N = 1e5+5, OO = 0x3f3f3f3f;
ll n, h, k, l, r, mid, ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h;
    vector<int> a, b;
    for(int i=0; i<n; ++i) {
        cin >> k;
        if (i & 1) b.push_back(k);
        else a.push_back(k);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    pair<int, int> best = {2*N, 0};
    for(int i=1, j=h, now; i<=h; ++i, --j){
        l = 0, r = n/2-1, ans = n/2;
        while (l <= r){
            mid = (l+r)/2;
            if(a[mid] < i) ans = mid, r = mid-1;
            else l = mid+1;
        }

        now = ans, l = 0, r = n/2-1, ans = n/2;
        while (l <= r){
            mid = (l+r)/2;
            if(b[mid] < j) ans = mid, r = mid-1;
            else l = mid+1;
        }

        now += ans;
        if(best.first > now) best.first = now;
    }

    for(int i=1, j=h, now; i<=h; ++i, --j){
        l = 0, r = n/2-1, ans = n/2;
        while (l <= r){
            mid = (l+r)/2;
            if(a[mid] < i) ans = mid, r = mid-1;
            else l = mid+1;
        }
        now = ans, l = 0, r = n/2-1, ans = n/2;
        while (l <= r){
            mid = (l+r)/2;
            if(b[mid] < j) ans = mid, r = mid-1;
            else l = mid+1;
        }
        now += ans;
        if(best.first == now) best.second++;
    }


    cout << best.first << ' ' << best.second;

    return 0;
}

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};

const int N = 1E5+5, OO = 0x3f3f3f3f;
int x[N], h[N], n;

map<pair<int, int>, int> mem;

int dp(int i, int right){
    if(i == n) return 0;

    if(mem.find({i, right}) != mem.end())
        return mem[{i, right}];

    int &ret = mem[{i, right}];

    int leave = dp(i+1, x[i]), lef = -1E9, rig = -1E9;
    if(x[i]-h[i] > right) lef = 1 + dp(i+1, x[i]);
    if(x[i]+h[i] < x[i+1]) rig = 1 + dp(i+1, x[i]+h[i]);

    return ret = max({leave, lef, rig});
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; ++i) cin >> x[i] >> h[i];
    x[n] = 2E9 + 10, h[n] = 0;

    cout << 1 + dp(1, x[0]);

    return 0;
}

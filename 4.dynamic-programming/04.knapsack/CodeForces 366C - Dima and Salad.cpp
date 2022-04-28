#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};

const int N = 1E2+5, M = 2E5+5, OO = 0x3f3f3f3f;
int n, k, t[N], c[N], mem[N][M][2];

int dp(int i, int tot, bool taken){
    if(i == n){
        if(tot == 100000 && taken) return 0;
        return -1E9;
    }

    int &ret = mem[i][tot][taken];
    if(~ret) return ret;

    int p1 = dp(i+1, tot, taken);
    int p2 = t[i] + dp(i+1, tot + t[i]-c[i]*k, true);

    return ret = max(p1, p2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; cin >> t[i++]);
    for(int i=0; i<n; cin >> c[i++]);

    memset(mem, -1, sizeof mem);
    cout << max(dp(0, 100000, 0), -1);

    return 0;
}

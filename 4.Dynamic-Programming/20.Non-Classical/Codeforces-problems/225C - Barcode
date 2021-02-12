#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};

const int N = 1005, OO = 0x3f3f3f3f;
int bar[N], mem[N][N][3];
int n, m, x, y;
char ch;

int dp(int j, int len, int prev){
    if(j == m){
        if(len < x) return 1E7;
        return 0;
    }

    int &ret = mem[j][len][prev];
    if(~ret) return ret;

    int p1 = 1E7, p2 = 1E7;
    if(j == 0 || (prev == 0 && len+1 <= y) || (prev == 1 && len >= x))
        p1 = n - bar[j] + dp(j+1, (prev == 0) ? len + 1 : 1, 0);
    if(j == 0 || (prev == 1 && len+1 <= y) || (prev == 0 && len >= x))
        p2 = bar[j] + dp(j+1, (prev == 1) ? len + 1 : 1, 1);
    
    return ret = min(p1, p2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin >> ch, bar[j] += (ch == '.');

    memset(mem, -1, sizeof mem);
    cout << dp(0, 0, 2);

    return 0;
}

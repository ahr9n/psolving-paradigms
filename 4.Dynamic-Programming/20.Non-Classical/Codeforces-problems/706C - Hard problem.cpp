#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};

const int N = 1E5+5, OO = 0x3f3f3f3f;
ll n, cost[N], mem[N][2];
string s[N], rev[N];

ll dp(int i, bool reversed){
    if(i == n) return 0;

    ll &ret = mem[i][reversed];
    if(~ret) return ret;

    ll p1 = 1E15, p2 = 1E15, p3 = 1E15;
    if(reversed){
        if(rev[i-1] <= s[i]) p1 = dp(i+1, 0); /// leave
        else{ /// can't just leave
            if(rev[i-1] <= rev[i]) p2 = cost[i] + dp(i+1, 1); /// must reverse
            else return ret = 1E15; /// imposible way
        }
        if(rev[i-1] <= rev[i]) p3 = cost[i] + dp(i+1, 1); /// free to reverse
    }else{ /// can't just leave
        if(s[i-1] <= s[i]) p1 = dp(i+1, 0); /// leave
        else{
            if(s[i-1] <= rev[i]) p2 = cost[i] + dp(i+1, 1); /// must reverse
            else return ret = 1E15; /// imposible way
        }
        if(s[i-1] <= rev[i]) p3 = cost[i] + dp(i+1, 1); /// free to reverse
    }

    return ret = min({p1, p2, p3});
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; cin >> cost[i++]);
    for(int i=0; i<n; ++i){
        cin >> s[i], rev[i] = s[i];
        reverse(rev[i].begin(), rev[i].end());
    }

    memset(mem, -1, sizeof mem);

    ll ans = min(dp(1, 1) + cost[0], dp(1, 0));
    cout << (ans >= 1E15 ? -1 : ans);

    return 0;
}

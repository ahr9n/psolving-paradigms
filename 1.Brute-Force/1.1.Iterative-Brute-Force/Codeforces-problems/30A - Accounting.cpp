#include <bits/stdc++.h>

using namespace std;

#define to(i, a, n)      for(ll i=a; i<n; i++)

typedef long long ll;
typedef long double ld;

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, n; cin >> a >> b >> n;

    if(!a && b) return cout << "No solution", 0;
    if(!b) return cout << 0, 0;
    if(b%a) return cout << "No solution", 0;

    to(i, -1010, 1010){
        ll x = 1, mult = i, nono = -1;
        to(j, 0, n){
            x *= mult;
            if(abs(x) > 1000) break;
            nono = j+1;
        }
        if(a*x == b && nono == n) return cout << i, 0;
    }
    cout << "No solution";

    return 0;
}

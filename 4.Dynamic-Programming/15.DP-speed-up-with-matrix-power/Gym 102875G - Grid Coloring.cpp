//Gym link: https://codeforces.com/gym/102875
#include <bits/stdc++.h>
using  namespace  std;
typedef  long long ll;

ll mod = 1e9 + 7;
struct Matrix{
    ll a[15][15];
    int n;
    Matrix(int nn) : n(nn){};
    Matrix operator *(Matrix other){
        Matrix prod(n);
        memset(prod.a, 0, sizeof prod.a);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                {
                    prod.a[i][k] += (a[i][j] * other.a[j][k]) % mod;
                    prod.a[i][k] %= mod;
                }

        return prod;
    }
};
Matrix unity(int n){
    Matrix a(n);
    memset(a.a, 0, sizeof a.a);

    for(int i = 0; i < n; i++)
        a.a[i][i] = 1;

    return a;
}
Matrix power(Matrix a, ll n, int sz){
    Matrix res = unity(sz);
    while(n)
    {
        if(n & 1) res = res * a;
        a = a * a;
        n /= 2;
    }
    return res;
}
ll fib(ll x, ll y, ll n){
    Matrix m(2);
    m.a[0][0] = 1;
    m.a[0][1] = 1;
    m.a[1][0] = 1;
    m.a[1][1] = 0;

    m = power(m, n - 1, 2);
    ll ans = m.a[1][0] * y % mod + m.a[1][1] * x % mod;
    ans = (ans % mod + mod) % mod;
    return ans;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        if(n > m) swap(n, m);
        if(n == 1)
            cout<<fib(2, 4, m)<<"\n";
        else if(n == 2){
            ll ans = fib(2, 4, m);
            ans = ans * ans % mod;
            cout<<ans<<"\n";
        }
        else if(n == 3){
            if(m == 3) cout<<"32\n";
            else{
                m -= 3;
                Matrix m3(3);
                m3.a[0][0] = 0;
                m3.a[0][1] = 1;
                m3.a[0][2] = 0;
                m3.a[1][0] = 1;
                m3.a[1][1] = 1;
                m3.a[1][2] = -1;
                m3.a[2][0] = 0;
                m3.a[2][1] = 0;
                m3.a[2][2] = 1;

                m3 = power(m3, m - 1, 3);
                ll ans = m3.a[0][0] * 44 % mod + m3.a[0][1] * 64 % mod + m3.a[0][2] * 4 % mod;
                ans = (ans % mod + mod) % mod;
                cout<<ans<<"\n";
            }
        }
        else if(n == 4){
            if(m == 4)
                cout<<"18\n";
            else
                cout<<"14\n";
        }
        else
            cout<<"8\n";
    }
}

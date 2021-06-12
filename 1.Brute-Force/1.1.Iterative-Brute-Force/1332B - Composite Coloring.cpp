#include <bits/stdc++.h>

using namespace std;

#define pi               acos(-1)
#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define Unique(n)        (n).erase(unique(inc(n)), (n).end())
#define what_is(x)       cerr << #x << " is " << x << '\n';
#define to(i, a, n)      for(int i=a; i<n; i++)
#define fr(i, a, n)      for(int i=a; i>=n; i--)
#define read(arr, l, r)  for(int i=l; i<r; cin >> arr[i++])
#define prnt(arr, l, r)  for(int i=l; i<r; cout << arr[i++] << " \n"[i==r])

typedef long long ll;
typedef long double ld;

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};

vector<int> ans[1005], res;
vector<int> primes;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    auto prime = [&](int u){
        for(int i=2, sqroot, ok; i<=u; i++){
            sqroot = sqrt(i), ok = 1;
            for(int j=2; j<=sqroot; j++)
                if(i%j == 0) ok = 0;
            if(ok) primes.push_back(i);
        }
    };
    prime(1000);

    auto check = [&](int u){
        for(int i=0; i<primes.size(); i++)
            if(u%primes[i] == 0) return primes[i];
    };

    int t, n, c; cin >> t;
    while(t--){
        cin >> n, c = 0;
        to(i, 1, 1001) ans[i].clear();
        vector<int> a(n), res(n);
        to(i, 0, n) cin >> a[i], ans[check(a[i])].push_back(i+1);
        to(i, 1, 1001) if(!ans[i].empty()){
            c++;
            for(auto it:ans[i]) res[it-1] = c;
        }
        cout << c << '\n';
        prnt(res, 0, n);
    }

    return 0;
}

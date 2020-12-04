/*  UntilDeathDoesUsApart
    DO   NOT   GIVE   UP!
*/

#include <bits/stdc++.h>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define pi               acos(-1)
#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define Unique(n)        (n).erase(unique(inc(n)), (n).end())
#define to(i, a, n)      for(int i=a; i<n; i++)
#define fr(i, a, n)      for(int i=a; i>=n; i--)
#define NumofDigits(n)   ((int)log10(n)+1)
#define isPowerOfTwo(n)  (n && !(n & (n - 1)))
#define read(arr, l, r)  for(int i=l; i<r; cin >> arr[i++])
#define prnt(arr, l, r)  for(int i=l; i<r; cout << arr[i++] << " \n"[i==r-1])

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 5, M = 1e6 + 5, OO = 0x3f3f3f3f;
int n, m, k, ne, head[N], nxt[M], to[M], u, v;

void init(){
    memset(head, -1, n*sizeof head[0]);
    ne = 0;
}

void addEdge(int f, int t){
    nxt[ne] = head[f];
    to[ne] = t;
    head[f] = ne++;
}

void addBiEdge(int u, int v){
    addEdge(u, v);
    addEdge(v, u);
}

void dfs(int u){
    if(vis[u]) return;
    vis[u] = 1;

    for(int k=head[u]; ~k; k=nxt[k])
        if(!vis[to[k]]) dfs(to[k]);
}

int sieve(int n);
unsigned long long pow(long long base, long long power);
long long gcd(long long a, long long b){ return a%b ? gcd(b, a%b) : b; }
long long lcm(long long a, long long b){ return a*b/gcd(a, b); }

void quicken(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
void file(){
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif /*ONLINE_JUDGE*/
}

int main(){
    quicken();

    return 0;
}

unsigned long long pow(long long base, long long power){  /// mod?
    if(power==0)
        return 1;
    if(power==1)
        return base;

    unsigned long long ans = pow(base, power/2); /// mod?
    ans *= ans; /// ((ans%mod)*(ans%mod))%mod;

    if(power&1)
        return ans*base; /// ((ans%mod)*(base%mod))%mod;
    return ans;
}

int sieve(int n){
    int c = 0;
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = 0;

    for(long long i=2; i*i<=n; i++)
        if(isPrime[i])
            for(long long j=i*2; j<=n; j+=i)
                isPrime[j] = 0;
    to(i, 0, n+1)
        if(isPrime[i]) c++;
    return c; /// primeCount [1:n]
}

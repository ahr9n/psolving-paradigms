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

long long b, s, c, nb, ns, nc, pb, ps, pc, rubles;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> rubles;


    auto can = [&](long long x){
        long long i, j, k;
        i = max((x*b-nb), (long long)0)*pb;
        j = max((x*s-ns), (long long)0)*ps;
        k = max((x*c-nc), (long long)0)*pc;
        return i+j+k;
    };

    to(i, 0, str.size())
        if(str[i]=='B') b++;
        else if(str[i]=='S') s++;
        else c++;

    long long l=0, r=1e13, mid, ans;
    while(l<=r){
        mid = (l+r)/2;
        if(can(mid)<=rubles)
            ans = mid, l = mid+1;
        else r = mid-1;
    }
    cout << ans;

    return 0;
}

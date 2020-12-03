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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, evenness, ev, od; cin >> n, evenness = n;
    to(i, 0, n){
        cin >> k;
        if(k & 1) od = i+1, evenness--;
        else ev = i+1;
    }
    cout << (evenness == 1 ? ev : od);

    return 0;
}

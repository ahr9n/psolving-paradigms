#include <bits/stdc++.h>

using namespace std;

#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define to(i, a, n)      for(int i=a; i<n; i++)
#define fr(i, a, n)      for(int i=a; i>=n; i--)
#define read(arr, l, r)  for(int i=l; i<r; cin >> arr[i++])
#define prnt(arr, l, r)  for(int i=l; i<r; cout << arr[i++] << " \n"[i==r-1])

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 5, M = 1e6 + 5, OO = 0x3f3f3f3f;
int n, m, k, t, a, b, c;
vector<int> w(k);
vector<string> ans = {"Carrots", "Kiwis", "Grapes"};

int idx(int i, int j){
    return (i*m + j);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> t;

    while(k--) cin >> a >> b, w.push_back(idx(--a, --b));
    sort(inc(w));

    while(t--){
        cin >> a >> b, --a, --b;
        if(binary_search(inc(w), idx(a, b))) cout << "Waste\n";
        else{
            c = lower_bound(inc(w), idx(a, b)) - w.begin();
            cout << ans[(idx(a, b) - c) % 3] << '\n';
        }
    }

    return 0;
}

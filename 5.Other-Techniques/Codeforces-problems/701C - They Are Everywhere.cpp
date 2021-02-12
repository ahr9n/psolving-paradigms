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

    int n;
    string s; cin >> n >> s;

    int l, r, mini, cur, tot;
    l = r = cur = 0, mini = n;
    map<char, int> mp;
    to(i, 0, n) mp[s[i]];
    tot = mp.size(), mp.clear();

    while(l<=r){
        while(cur!=tot && r<n)
            mp[s[r++]]++, cur = mp.size();

        if(cur==tot) mini = min(mini, r-l);
        if(mp[s[l]]==1) cur--, mp.erase(s[l++]);
        else mp[s[l++]]--;
    }

    cout << mini;

    return 0;
}

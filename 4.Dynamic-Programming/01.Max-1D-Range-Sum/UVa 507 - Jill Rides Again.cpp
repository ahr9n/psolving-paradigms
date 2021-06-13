/*  UntilDeathDoesUsApart
    DO   NOT   GIVE   UP!
*/

#include <bits/stdc++.h>

using namespace std;

#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define Unique(n)        (n).erase(unique(in(n)), (n).end())
#define to(i, a, n)      for(int i=a; i<n; i++)
#define fr(i, a, n)      for(int i=a; i>=n; i--)
#define read(arr, l, r)  for(int i=l; i<r; cin >> arr[i++])
#define prnt(arr, l, r)  for(int i=l; i<r; cout << arr[i++] << " \n"[i==r])

typedef long long ll;
typedef long double ld;

const int N = 2E4 + 4;
int t, n, arr[N], maxi, maxo, l, r;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    to(j, 1, t+1){
        cin >> n;
        read(arr, 1, n);

        vector<pair<int, pair<int, pair<int, int>>>> v;
        l = 1, maxi = maxo = 0;
        for(int i=1; i<n; i++){
            maxi += arr[i];
            if(maxi < 0) maxi = 0, l = i+1;
            else if(maxi >= maxo)
                v.push_back({maxi, {i-l, {l, i+1}}}), maxo = maxi;
        }

        sort(dec(v));
        if(v.size()){
            to(k, 0, v.size())
                if(v[0].second.first == v[k].second.first)
                    l = v[k].second.second.first, r = v[k].second.second.second;
                else break;

            cout << "The nicest part of route " << j << " is between stops ";
            cout << l << " and " << r << '\n';
        }else cout << "Route " << j << " has no nice parts\n";
    }

    return 0;
}

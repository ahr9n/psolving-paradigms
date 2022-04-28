/*	MASTER HAS FAILED MORE TIMES
	THAN BEGINNER HAS EVER TRIED
*/

#include <bits/stdc++.h>

using namespace std;

#define endl             '\n'
#define all(a)           a.begin(), a.end()
#define mem(a, n)        memset(a, n, sizeof(a))
#define Unique(n)        (n).erase(unique(all(n)), (n).end())
#define NumofDigits(n)   ((long long)log10(n)+1)
#define repeat(i, a, n)  for(int i=a; i<n; i++)
#define isPowerOfTwo(n)  (n && !(n & (n - 1)))

typedef long long ll;
typedef long double ld;

void quicken(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
void file(){
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif /*ONLINE_JUDGE*/
}

int main(){
    quicken();

    vector<ll> v, pref;
    repeat(i, 0, 34) v.push_back(pow(2, i)), pref.push_back(pow(2, i));
    repeat(i, 0, 33) pref[i+1] += pref[i];

    long long maxi, cur;
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        ll arr[n];
        repeat(i, 0, n) cin >> arr[i];

        maxi = -1E10, cur = 0;
        repeat(i, 1, n)
            if(arr[i-1]>arr[i]){
                maxi = max(arr[i-1]-arr[i], maxi);
                arr[i] = arr[i-1];
            }
        maxi = max((ll)0, maxi);
        cout << (ll)max(0.0, log2(maxi)+1) << '\n';
    }

    return 0;
}

/*	MASTER HAS FAILED MORE TIMES
	THAN BEGINNER HAS EVER TRIED
*/

#include <bits/stdc++.h>

using namespace std;

#define endl            '\n'
#define mem(a, n)       memset(a, n, sizeof(a))
#define repeat(n)       for(int i=0; i<n; i++)
#define Unique(n)       (n).erase(unique(all(n)), (n).end())
#define isPowerOfTwo(n) (n && !(n & (n - 1)))
#define NumofDigits(n)  ((int)log10(n)+1)
#define all(a)          a.begin(), a.end()

long long gcd(long long a, long long b){ return a%b ? gcd(b, a%b) : b; }
long long lcm(long long a, long long b){ return a*b/gcd(a, b); }

void quicken(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

/*
    Special functions:
        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

int main(){
    quicken();

    int t, n, m, k, l, r, mini, cur, i=0; cin >> t;
	while(t--){
		cin >> n >> m >> k;
        l = r = cur = 0, mini = INT_MAX;

		int arr[n+1];
        map<int, int> mp;
		arr[0] = 1, arr[1] = 2, arr[2] = 3;
        for(int i=3; i<=n; i++)
            arr[i] = (arr[i-1]+arr[i-2]+arr[i-3])%m +1;

		while(l<=r && r<n){
            while(cur!=k && r<n){
                if(arr[r]<=k) mp[arr[r]]++;
                r++, cur = mp.size();
            }

            if(cur==k) mini = min(mini, r-l);

            if(arr[l] <= k && mp[arr[l]]==1)
                mp.erase(arr[l]), cur--;
            else if(arr[l] <= k) mp[arr[l]]--;
            l++;
        }

        cout << "Case " << ++i << ": ";
        if(mini==INT_MAX) cout << "sequence nai" << endl;
        else cout << mini << endl;
	}

}

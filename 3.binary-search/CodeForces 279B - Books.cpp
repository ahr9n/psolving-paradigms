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

void quicken(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

/*
    Special functions:
        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

int main(){
    quicken();

    long long n, t; cin >> n >> t;
    long long arr[n], l, r, sum, ans;
    repeat(n) cin >> arr[i];

    /// lovely caterpillar method :)
  
    l = r = sum = ans = 0;
    while(r<n){
        if(arr[r]+sum<=t)
            sum += arr[r++], ans = max(ans, abs(r-l));
        else sum -= arr[l++];
    }
    cout << ans;
}

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

    int n, l, r; cin >> n;
    long long arr[n], ans, a, c;
    repeat(n) cin >> arr[i];

    l = ans = a = c = 0, r = n-1;
    while(l<=r){
        a <= c ? a += arr[l++] : c += arr[r--];
        if(a==c) ans = a;
    }
    cout << ans;
}

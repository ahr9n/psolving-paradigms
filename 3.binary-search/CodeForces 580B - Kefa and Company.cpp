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

    long long n, d, ans, maxi=0; cin >> n >> d;
    pair<long long, long long> p[n+1];
    p[0].first = p[0].second = 0;

    repeat(n) cin >> p[i+1].first >> p[i+1].second;
    sort(p, p+n+1);
    repeat(n) p[i+1].second += p[i].second;

    int l, r, mid;
    repeat(n){
        l = i+1, r = n+1, ans = 0;
        while(l<=r){
            mid = (l+r)/2;
            if(abs(p[i+1].first-p[mid].first) < d)
                ans = p[mid].second-p[i].second, l = mid+1;
            else r = mid-1;
        }
        maxi = max(maxi, ans);
    }
    cout << maxi << endl;

    return 0;
}

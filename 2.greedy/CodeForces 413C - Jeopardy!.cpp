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

long long sum(long long n){ return n*(n+1)/2; }
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

    int n, m, b; cin >> n >> m;
    long long price[n], all = 0, sum = 0;
    repeat(n) cin >> price[i], all += price[i];

    vector<long long> auc;
    repeat(m)
        cin >> b, auc.push_back(price[--b]), sum += auc[i];
    sort(all(auc)), reverse(all(auc));

    all -= sum, sum = all;
    for(int i=0; i<m; i++)
        if(auc[i]<=sum) sum += sum;
        else sum += auc[i];

    cout << sum;
    return 0;
}

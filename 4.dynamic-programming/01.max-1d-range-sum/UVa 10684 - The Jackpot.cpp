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

unsigned long long pow(long long base, long long power);

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

    int n;
    while(cin >> n && n){
        int arr[n], maxi = 0, maxo = 0;
        repeat(n) cin >> arr[i];
        repeat(n){
            maxi = max(arr[i], maxi+arr[i]); /// previous maxi is a subarray, next is a new one :P
            maxo = max(maxi, maxo);          /// max of maxi
            /// Maximum Subarray Sum problem
        }
        if(maxo > 0) cout << "The maximum winning streak is " << maxo << "." << endl;
        else cout << "Losing streak." << endl;
    }

    return 0;
}

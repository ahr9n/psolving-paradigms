#include "bits/stdc++.h"

using namespace std;

#define endl           '\n'
#define repeat(n)      for(int i=0; i<n; i++)
#define NumofDigits(n) ((int)log10(n)+1)

void quicken(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main(){
    quicken();

    long long n, k; cin >> n >> k;
    n = n-1;
    k = k-1;

    if(!n) return cout << 0, 0;
    if(k*(k+1)/2 < n) return cout << -1, 0;
    long long l=0, r=k, mid;

    while(l<=r){
        mid = (l+r)/2;
        if((mid+k)*(k-mid+1)/2 >= n) l = mid+1;
        else r = mid-1;
    }
    return cout << k-l+2, 0;
}

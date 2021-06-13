#include <bits/stdc++.h>

using namespace std;

#define endl            '\n'
#define repeat(n)       for(int i=0; i<n; i++)
#define EPS             1E-7

void quicken(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int sum(long long n){
    int s = 0;
    while(n) s += n%10, n /= 10;
    return s;
}

int main(){
    quicken();

    long long n, s, l, r, mid; cin >> n >> s;
    l = 1, r = n;
    while(l<=r){
        mid = (l+r)/2;
        if(mid-sum(mid)<s)
            if(mid+1 - sum(mid+1)<s) l = mid+1;
            else return cout << n-mid, 0;
        else r=mid-1;
    }
    cout << 0, 0;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define endl            '\n'
#define mem(a , b)      memset(a , b , sizeof(a))
#define repeat(n)       for(int i=0; i<n; i++)
#define NumofDigits(n)  ((int)log10(n)+1)

void quicken(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main(){
    quicken();

    int n, q, l, r, mid; cin >> n;
    long long arr[n], ans, m;
    repeat(n) cin >> arr[i];

    sort(arr, arr+n);
    cin >> q;
    while(q--){
        cin >> m;
        l = 0, r = n-1, ans = -1;
        while(l<=r){
            mid = (l+r)/2;
            if(arr[mid]<=m) ans=mid, l=mid+1;
            else r = mid-1;
        }
        cout << ans+1 << endl;
    }

    return 0;
}

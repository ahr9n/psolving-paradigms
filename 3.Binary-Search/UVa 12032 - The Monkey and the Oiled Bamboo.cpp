#include "bits/stdc++.h"

using namespace std;

#define endl            '\n'
#define repeat(n)       for(int i=0; i<n; i++)

void quicken(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

int main(){
    quicken();

    int t, n, j=0; cin >> t;
    while(t--){
        cin >> n;
        int arr[n], maxi, ans;
        repeat(n) cin >> arr[i];

        maxi = arr[0];
        repeat(n-1) maxi = max(maxi, arr[i+1]-arr[i]);
        ans = maxi;

        if(maxi == arr[0]) maxi--;
        repeat(n-1)
            if(maxi == arr[i+1]-arr[i]) maxi--;
            else if(maxi < arr[i+1]-arr[i]){
                ans++; break;
            }

        cout << "Case " << ++j << ": " << ans << endl;
    }

    return 0;
}

/*
2
3
3 6 9
3
3 5 8
*/

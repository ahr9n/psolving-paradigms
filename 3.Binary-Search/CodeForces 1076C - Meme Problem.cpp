#include <bits/stdc++.h>

using namespace std;

#define endl            '\n'
#define repeat(n)       for(int i=0; i<n; i++)
#define EPS             1E-7

void quicken(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main(){
    quicken();

    int t; cin >> t;
    double d, l, r, mid, a;
    while(t--){
        cin >> d;
        l = 0, r = d, a = -1;
        while(l<=r){
            mid = (l+r)/2;
            if(abs((mid*(d-mid))-(mid+(d-mid))) <= EPS){ a=mid; break; }
            else if(mid*(d-mid) < d) l = mid+EPS*EPS;
            else                     r = mid-EPS*EPS;
        }
        if(a==-1){ cout << "N" << endl; continue; }
        cout << fixed << setprecision(9) << "Y " << a << " " << d-a << endl;
    }

    return 0;
}

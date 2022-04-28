#include <bits/stdc++.h>
 
using namespace std;
 
#define endl           '\n'
#define repeat(n)   for(int i=0; i<n; i++)
#define NumofDigits(n) ((int)log10(n)+1)
 
void quicken(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
 
int q, n, x, maxi, t, res;
pair <int, int> a[101];
 
int main(){
    quicken();
 
    cin >> q;
    while(q--) {
        maxi = t = 0;
        cin >> n >> x;
        repeat(n){ 
            cin >> a[i].first >> a[i].second;
            maxi = max(maxi, a[i].first);
            t = max(t, a[i].first-a[i].second);
        }
        if(x <= maxi){
            cout << 1 << endl;
            continue;
        }
        if(!t){
            cout << -1 << endl;
            continue;
        }
        res = (x-maxi)/t;
        if ((x-maxi)%t != 0) res++;
 
        cout << res+1 << endl;
    }
}

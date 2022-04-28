#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {1, -1, 0,  0, -1, -1, -1,  1, 1, 1};
int dy[] = {0,  0, 1, -1, -1,  0,  1, -1, 0, 1};

const int N = 1e2+5;
ll est, n, k, ne, po, z1, z2, ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> est;
    for(int t=1; t<=est; ++t) {
        cin >> n, ans = 0;
//        vector<ll> neg1, pos1, neg2, pos2;
//        for(int i=0; i<n; ++i){
//            cin >> k;
//            if(!k) ++z1;
//            else if(k > 0) pos1.push_back(k);
//            else neg1.push_back(k);
//        }
//        for(int i=0; i<n; ++i){
//            cin >> k;
//            if(!k) ++z2;
//            else if(k > 0) pos2.push_back(k);
//            else neg2.push_back(k);
//        }
//        sort(neg1.rbegin(), neg1.rend());
//        sort(pos1.begin(), pos1.end());
//        sort(neg2.rbegin(), neg2.rend());
//        sort(pos2.begin(), pos2.end());
//
//        while (!neg1.empty() && !pos2.empty()) {
//            ans += neg1.back() * pos2.back();
//            neg1.pop_back(), pos2.pop_back();
//        }
//        while (!neg2.empty() && !pos1.empty()) {
//            ans += neg2.back() * pos1.back();
//            neg2.pop_back(), pos1.pop_back();
//        }
//        while (!pos2.empty() && z1) z1--, pos2.pop_back();
//        while (!pos1.empty() && z2) z2--, pos1.pop_back();
//
//        while (!neg2.empty() && z1) z1--, neg2.pop_back();
//        while (!neg1.empty() && z2) z2--, neg1.pop_back();
//
//        if(!pos1.empty()) reverse(pos1.begin(), pos1.end());
//        while (!pos1.empty() && !pos2.empty()) {
//            ans += pos1.back() * pos2.back();
//            pos1.pop_back(), pos2.pop_back();
//        }
//
//        if(!neg1.empty()) reverse(neg1.begin(), neg2.end());
//        while (!neg1.empty() && !neg2.empty()) {
//            ans += neg1.back() * neg2.back();
//            neg1.pop_back(), neg2.pop_back();
//        }
        
        vector<ll> a(n), b(n);
        for(int i=0; i<n; cin >> a[i++]);
        for(int i=0; i<n; cin >> b[i++]);
        
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        for(int i=0; i<n; ans += a[i]*b[i], i++);
        
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}

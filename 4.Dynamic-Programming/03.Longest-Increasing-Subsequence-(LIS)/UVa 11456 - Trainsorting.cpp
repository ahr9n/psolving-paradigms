#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};

int t, n, k, ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--){
        cin >> n, ans = (n == 0 ? 0 : 1);
        vector<int> train(n), LIS(n, 1), LDS(n, 1);
        for(int i=n-1; i>=0; cin >> train[i--]);

        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(train[j] < train[i]) LIS[i] = max(LIS[i], LIS[j]+1);
                if(train[j] > train[i]) LDS[i] = max(LDS[i], LDS[j]+1);
            }
            ans = max(ans, LIS[i]+LDS[i]-1);
        }
        cout << ans << '\n';
    }

    return 0;
}

#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;

int n, r, ans;

vector<int> LIS(vector<int> a){

    vector<int> lst(n), rt(n);
    r = 0;

    for (int i = 0, idx; i < n; ++i) {
        idx = lower_bound(lst.begin(), lst.begin() + r, a[i]) - lst.begin();
        if(idx == r) ++r;
        rt[i] = idx + 1, lst[idx] = a[i];
    }
    return rt;
}

class IntegerSequence {
public:
    int maxSubsequence(vector<int> arr) {
        ios_base::sync_with_stdio(0), cin.tie(0);

        /**
         * x <= lower_bound(x)
         * x <  upper_bound(x)
         */

        n = arr.size();

        vector<int> lis = LIS(arr);
        reverse(arr.begin(), arr.end());
        vector<int> lds = LIS(arr);
        reverse(lds.begin(), lds.end());

        ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, lis[i] + lds[i] - 1);

        return arr.size() - ans;
    }
};

//int main(){
//    IntegerSequence test;
//    cout << test.maxSubsequence({1, 4, 6, 5, 2, 1}) << '\n';
//    cout << test.maxSubsequence({1, 2, 1, 2, 3, 2, 1, 2, 1}) << '\n';
//    cout << test.maxSubsequence({2, 2, 2, 2, 2}) << '\n';
//    cout << test.maxSubsequence({4,5,65,34,786,45678,987,543,2,6,98,580,4326,754,54,2,1,3,5,6,8,765,43,3,54}) << '\n';
//}

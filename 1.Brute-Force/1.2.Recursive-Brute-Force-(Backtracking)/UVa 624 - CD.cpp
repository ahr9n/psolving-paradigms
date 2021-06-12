/*	MASTER HAS FAILED MORE TIMES
	THAN BEGINNER HAS EVER TRIED
*/

#include <bits/stdc++.h>

using namespace std;

#define endl            '\n'
#define mem(a, n)       memset(a, n, sizeof(a))
#define repeat(i, n)    for(int i=0; i<n; i++)
#define Unique(n)       (n).erase(unique(all(n)), (n).end())
#define isPowerOfTwo(n) (n && !(n & (n - 1)))
#define NumofDigits(n)  ((int)log10(n)+1)
#define all(a)          a.begin(), a.end()

void quicken(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

int main(){
    quicken();

    int n, t, ans, maxi, sum, tot;
    while(cin >> n >> t){
        int arr[t];
        repeat(i, t) cin >> arr[i];

        maxi = ans = 0, tot = pow(2, t);
        repeat(i, tot){
            bitset<20> bt(i);
            sum = 0;
            repeat(j, t)
                if(bt[j]) sum += arr[j];
            if(sum<=n && maxi<=sum) ans = i, maxi = sum;
        }
        bitset<20> bt(ans);
        repeat(i, t)
            if(bt[i]) cout << arr[i] << ' ';
        cout << "sum:" << maxi << endl;
    }

    return 0;
}

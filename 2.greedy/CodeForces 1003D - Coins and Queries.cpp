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

    int n, q; cin >> n >> q;
    long long a, b, c, d, two[32]={0};
    repeat(n) cin >> a, two[(int)log2(a)]++;

    while(q--){
        cin >> b;
        a = 0;
        for(int i=31; i>=0; i--){
            d = pow(2, i);
            c = min(b/d, two[i]);
            a += c, b = b - d*c;
        }
        cout << (b ? -1 : a) << endl; /// to be or not
    }
    return 0;
}

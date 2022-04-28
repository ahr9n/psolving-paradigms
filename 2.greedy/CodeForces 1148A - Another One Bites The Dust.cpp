#include <bits/stdc++.h>

using namespace std;

#define endl            '\n'
#define mem(a, b)       memset(a , b , sizeof(a))
#define repeat(n)       for(int i=0; i<n; i++)
#define NumofDigits(n)  ((int)log10(n)+1)

void quicken(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

/*
    Special functions:
        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

int main(){
    quicken();

    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /// ONLINE_JUDGE

    long long a, b, c;
    cin >> a >> b >> c;

    cout << c*2 + min(a, b)*2 + (a!=b);

    return 0;
}

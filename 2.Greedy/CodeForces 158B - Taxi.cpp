#include <bits/stdc++.h>

using namespace std;

#define repeat(n)   for(int i=0; i<n; i++)

void quicken(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main(){
    quicken();

    #ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /// ONLINE_JUDGE

    int n, taxi=0, k, freq[5]={0}; cin >> n;
    repeat(n) cin >> k, freq[k]++;

    taxi = freq[3] + freq[4];
    taxi += (max(freq[1]-freq[3], 0)+3+2*freq[2])/4;

    cout << taxi;
    return 0;
}

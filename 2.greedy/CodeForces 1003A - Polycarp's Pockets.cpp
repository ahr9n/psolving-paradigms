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

    int n; cin >> n;
    int arr[n], freq[101]={0};
    repeat(n) cin >> arr[i], freq[arr[i]]++;

    cout << *max_element(freq, freq+101);
    return 0;
}

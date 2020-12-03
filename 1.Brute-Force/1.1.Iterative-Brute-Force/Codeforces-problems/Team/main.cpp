#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void quicken(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main(){
    quicken();

    short n; cin >> n;
    int arr[n][3], c, c0=0;
    for(int i=0; i<n; i++){
        c = 0;
        for(int j=0; j<3; j++)
            cin >> arr[i][j], c += arr[i][j];
        c0 += c/2;
    }
    cout << c0;

    return 0;
}

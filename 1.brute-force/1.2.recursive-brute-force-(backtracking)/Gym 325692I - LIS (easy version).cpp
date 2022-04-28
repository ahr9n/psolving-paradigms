#include <bits/stdc++.h>

using namespace std;

int n;
int arr[22];

int LIS(int i, int prev){
    if(i==n) return 0;

    int p1 = LIS(i+1, prev), p2 = 0;
    if(prev < arr[i])
        p2 = LIS(i+1, arr[i]) + 1;

    return max(p1, p2);
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << LIS(0, 0);
    return 0;
}

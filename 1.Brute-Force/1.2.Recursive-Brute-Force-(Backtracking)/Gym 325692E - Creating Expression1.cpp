#include <bits/stdc++.h>

using namespace std;

long long n, x, arr[21];

bool ok(int i, int sum){
    if(i==n) return (sum == x);

    return ok(i+1, sum+arr[i]) | ok(i+1, sum-arr[i]);
}

int main()
{
    cin >> n >> x;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << (ok(1, arr[0]) ? "YES" : "NO");

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, x, arr[21];

long long ok(int i, int sum){
    if(i==n) return (sum == x);

    return ok(i+1, sum+arr[i]) + ok(i+1, sum-arr[i]);
}

int main()
{
    cin >> n >> x;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << ok(1, arr[0]);

    return 0;
}

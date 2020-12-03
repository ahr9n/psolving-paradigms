#include <iostream>

using namespace std;

int main()
{
    int n, m, c=0;
    cin >> n >> m;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
           if(abs(arr[j]-arr[i])<=m) c++;

    cout << c*2;
    return 0;
}

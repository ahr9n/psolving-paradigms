/*	MASTER HAS FAILED MORE TIMES
	THAN BEGINNER HAS EVER TRIED
*/

#include <bits/stdc++.h>

using namespace std;

#define endl            '\n'
#define mem(a, n)       memset(a, n, sizeof(a))
#define repeai(a, n)    for(int i=a; i<n; i++)
#define repeaj(a, n)    for(int j=a; j<n; j++)
#define Unique(n)       (n).erase(unique(all(n)), (n).end())
#define isPowerOfTwo(n) (n && !(n & (n - 1)))
#define NumofDigits(n)  ((int)log10(n)+1)
#define all(a)          a.begin(), a.end()

long long sum(long long n){ return n*(n+1)/2; }
long long gcd(long long a, long long b){ return a%b ? gcd(b, a%b) : b; }
long long lcm(long long a, long long b){ return a*b/gcd(a, b); }

void quicken(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

/*
    Special functions:
        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
int t, n, k;
char arr[15][15];
map<char, int> mp;
void fillGrid(){
    repeai(1, n+1) repeaj(1, n+1){
        if(arr[i][j] != '.') continue;
        /* 1.2
           ...
           3.4 */
        if(arr[i][j]=='.' && arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i-1][j]
            && arr[i][j]==arr[i][j-1] && arr[i][j]==arr[i+1][j]) arr[i][j] = 'A';
        else{
            mp.clear();
            if(arr[i][j+1] != '.') mp[arr[i][j+1]]++;
            if(arr[i-1][j] != '.') mp[arr[i-1][j]]++;
            if(arr[i][j-1] != '.') mp[arr[i][j-1]]++;
            if(arr[i+1][j] != '.') mp[arr[i+1][j]]++;
            /* samples:
                A, B, C, D -> E
                A, A, A, B -> C
                C, D, D, E -> A
                A, D, C, E -> B
               so, we can see that the answer always will be: A, B, C, D, E
            */
            if(mp['A']==0) arr[i][j] = 'A';
            else if(mp['B']==0) arr[i][j] = 'B';
            else if(mp['C']==0) arr[i][j] = 'C';
            else if(mp['D']==0) arr[i][j] = 'D';
            else if(mp['E']==0) arr[i][j] = 'E';
        }
    }
}

int main(){
    quicken();

    cin >> t;
    while(t--){
        cin >> n;
        repeai(0, n+2) repeaj(0, n+2) arr[i][j] = '.';
        repeai(1, n+1) repeaj(1, n+1) cin >> arr[i][j];
        fillGrid();
        cout << "Case " << ++k << ':' << endl;
        repeai(1, n+1){
            repeaj(1, n+1) cout << arr[i][j];
            cout << endl;
        }
    }
    return 0;
}

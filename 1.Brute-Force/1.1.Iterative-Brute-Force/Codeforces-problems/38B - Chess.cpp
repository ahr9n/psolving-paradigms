#include <bits/stdc++.h>

using namespace std;

#define pi               acos(-1)
#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define Unique(n)        (n).erase(unique(inc(n)), (n).end())
#define what_is(x)       cerr << #x << " is " << x << '\n';
#define to(i, a, n)      for(int i=a; i<n; i++)
#define fr(i, a, n)      for(int i=a; i>=n; i--)
#define read(arr, l, r)  for(int i=l; i<r; cin >> arr[i++])
#define prnt(arr, l, r)  for(int i=l; i<r; cout << arr[i++] << " \n"[i==r])

typedef long long ll;
typedef long double ld;

int dx[] = {1, 2};
int dy[] = {2, 1};
int sx[] = {1, -1, 1, -1};
int sy[] = {-1, 1, 1, -1};

bool chess[8][8];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string rook, knight; cin >> rook >> knight;

    memset(chess, 0, sizeof chess);

    auto valid = [&](int i, int j){
        return (i<8 && i>=0 && j<8 && j>=0);
    };

    chess[knight[0]-'a'][knight[1]-'1'] = true;
    to(i, 0, 2) to(j, 0, 4){
        int x = knight[0]-'a' + dx[i]*sx[j];
        int y = knight[1]-'1' + dy[i]*sy[j];
        if(valid(x, y)) chess[x][y] = true;

        //cout << x << ' ' << y << '\n';
    }

    chess[rook[0]-'a'][rook[1]-'1'] = true;
    to(i, 0, 8) chess[i][rook[1]-'1'] = true;
    to(j, 0, 8) chess[rook[0]-'a'][j] = true;

    auto check = [&](int x, int y){
        to(i, 0, 2) to(j, 0, 4){
            int koko = x + dx[i]*sx[j];
            int soso = y + dy[i]*sy[j];
            if(valid(koko, soso) && ((koko==rook[0]-'a' && soso==rook[1]-'1')
            || (koko==knight[0]-'a' && soso==knight[1]-'1'))) return false;
        }
        return true;
    };

    int ans = 0;
    to(i, 0, 8) to(j, 0, 8)
        ans += !chess[i][j] & check(i, j);

    cout << ans;

    return 0;
}

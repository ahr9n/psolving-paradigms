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

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    pair<int, int> in, out;
    char maze[n][m];
    to(i, 0, n) to(j, 0, m){
        cin >> maze[i][j];
        if(maze[i][j] == 'S') in = {i, j};
        if(maze[i][j] == 'E') out = {i, j};
    }
    string s; cin >> s;

    int ans = 0, x, y;
    vector<int> mapping = {0, 1, 2, 3};

    do{
        x = in.first, y = in.second;
        for(auto it:s) {
            x += it == mapping[0]+'0';
            x -= it == mapping[1]+'0';
            y += it == mapping[2]+'0';
            y -= it == mapping[3]+'0';
            if(x<n && x>=0 && y<m && y>=0 && maze[x][y]!='#'){
                if(x == out.first && y == out.second) break;
            }else break;
        }
        ans += (x == out.first && y == out.second);
    }while(next_permutation(inc(mapping)));

    cout << ans;

    return 0;
}

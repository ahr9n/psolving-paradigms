#include <bits/stdc++.h>

using namespace std;

#define endl            '\n'
#define mem(a, b)       memset(a , b , sizeof(a))
#define repeat(n)       for(int i=0; i<n; i++)
#define NumofDigits(n)  ((int)log10(n)+1)

void quicken(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

/*
    Special functions:
        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

int main(){
    quicken();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /// ONLINE_JUDGE

    int n, mini=0; cin >> n;
    string str; cin >> str;
    char ch[3] = {'R', 'G', 'B'};
    map<char, int> mp;
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    str += " ";

    for(int i=1; i<n; i++)
        if(str[i]==str[i-1])
            for(int j=0; j<3; j++)
                if(str[i-1]!=ch[j] && ch[j]!=str[i+1]){
                    str[i] = ch[j], mini++; break;
                }

    cout << mini << endl << str;
}

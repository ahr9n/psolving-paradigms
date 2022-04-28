#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2E5 + 5, M = 2E6 + 10, MOD = 1E9 + 7;
int t, n, m, a[20][20];

string s, p;
vector<string> block;

bool check(){
    map<char, string> ch_st;
    for (int i = 0; i < block.size(); ++i) {
        if(ch_st[p[i]] != ""){
            if(block[i] != ch_st[p[i]]) return false;
        }else ch_st[p[i]] = block[i];
    }
    return true;
}

/**
    idsi vfd gvrg vfd idsi
    A    D   E    E   X
 */

bool solve(int i){
    // base case
    if(block.size() > p.size()) return false;
    
    if(i == s.size()){
        if(block.size() == p.size()) return check();
        return 0;
    }

    bool c1 = false, c2 = false;
    if(!block.empty()) {
        block.back().push_back(s[i]);
        c1 = solve(i + 1);
        block.back().pop_back();
    }

    block.push_back(string(1, s[i]));
    c2 = solve(i+1);
    block.pop_back();

    return (c1 | c2);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> t;
    while(t--){
        cin >> s >> p, block.clear();
        cout << (solve(0) ? "YES" : "NO") << '\n';
    }

    return 0;
}

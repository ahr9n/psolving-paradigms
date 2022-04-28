#include <bits/stdc++.h>

using namespace std;

int n, r;
string s;
set<vector<int>> st;
vector<int> v, sub;

void gen(int i){
    if(sub.size()==r){ st.insert(sub); return; }
    if(i==n) return;

    gen(i+1), sub.push_back(v[i]);
    gen(i+1), sub.pop_back();
}


int main(){

    cin >> n >> r;
    for(int i=1; i<=n; i++)
        v.push_back(i);

    do gen(0);
    while(next_permutation(v.begin(), v.end()));

    for(auto &it:st){
        for(auto &is:it) cout << is << ' ';
        cout << '\n';
    }
    return 0;
}

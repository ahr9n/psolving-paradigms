#include <bits/stdc++.h>

using namespace std;

int n, r;
string s;
set<vector<string>> st;
vector<string> v, sub;

void gen(int i){
    if(sub.size()==r){ st.insert(sub); return; }
    if(i==n) return;

    gen(i+1), sub.push_back(v[i]);
    gen(i+1), sub.pop_back();
}


int main(){

    cin >> n >> r;
    for(int i=0; i<n; i++)
        cin >> s, v.push_back(s);

    sort(v.begin(), v.end());
    gen(0);

    for(auto &it:st){
        for(auto &is:it)
            cout << is << ' ';
        cout << '\n';
    }

    return 0;
}

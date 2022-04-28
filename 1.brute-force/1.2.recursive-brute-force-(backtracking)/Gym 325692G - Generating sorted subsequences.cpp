#include <bits/stdc++.h>

using namespace std;

int n, sz;
int arr[21];
multiset<vector<int>> s;

vector<int> v;
void gen(int i){
    if(! is_sorted(v.begin(), v.end())) return;
    if(i==n && v.size()) s.insert(v);
    if(i==n) return;

    v.push_back(arr[i]), gen(i+1);
    v.pop_back(), gen(i+1);
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    gen(0);
    for(auto it:s){
        set<int> st;
        for(auto is:it) st.insert(is);
        if(st.size() != it.size()) continue;

        for(auto is:it) cout << is << ' ';
        cout << '\n';
    }

    return 0;
}

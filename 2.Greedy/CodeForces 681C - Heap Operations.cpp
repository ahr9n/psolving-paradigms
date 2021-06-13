#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n;
    vector<pair<string, int>> ans;

    multiset<int> st;
    while (n--){
        string s; cin >> s;
        if(s == "removeMin") {
            if (st.empty()) {
                ans.push_back({"insert", 0});
            }else st.erase(st.begin());
            ans.push_back({s, 0});
        }else{
            cin >> k;
            if(s == "insert"){
                st.insert(k);
                ans.push_back({s, k});
            }else{
                if(st.empty()){
                    ans.push_back({"insert", k});
                    st.insert(k);
                }else{
                    if(*st.begin() > k){
                        ans.push_back({"insert", k});
                        st.insert(k);
                    }else if(*st.begin() < k){
                        while (!st.empty()){
                            if(*st.begin() >= k) break;
                            ans.push_back({"removeMin", 0});
                            st.erase(st.begin());
                        }
                        if(st.empty()){
                            ans.push_back({"insert", k});
                            st.insert(k);
                        }else if(*st.begin() > k){
                            ans.push_back({"insert", k});
                            st.insert(k);
                        }
                    }
                }
                ans.push_back({s, k});
            }
        }
    }

    cout << ans.size() << '\n';
    for(auto it:ans){
        if(it.first == "removeMin") cout << it.first;
        else cout << it.first << ' ' << it.second;
        cout << '\n';
    }

    return 0;
}

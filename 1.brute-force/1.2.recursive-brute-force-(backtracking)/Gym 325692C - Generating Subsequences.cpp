#include <bits/stdc++.h>

using namespace std;

int n;
string str;
multiset<string> s; // dup

void gen(string t, int i){
    if(i==n){
        if(t.size()) s.insert(t);
        return;
    }

    gen(t, i+1);
    t += str[i];

    gen(t, i+1);
}

int main(){
    cin >> str, n = str.size();

    gen("", 0);
    for(string it:s)
        cout << it << '\n';

    return 0;
}

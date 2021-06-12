#include <bits/stdc++.h>

using namespace std;

int t, n;
set<string> s;

bool sum(string str){
    string x = str.substr(0, str.length()/2);
    string y = str.substr(str.length()/2, str.length()/2);
    int a = 0, b = 0;
    for(char c:x) a += (c-'0');
    for(char d:y) b += (d-'0');
    return a == b;
}

void bin(string str, int len){
    if(len>2*n) return;
    if(len==2*n && sum(str)) s.insert(str);
    bin(str+"0", len+1);
    bin(str+"1", len+1);
}

int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        bin("", 0);

        for(string it:s)
            cout << it << '\n';
        s.clear();
    }

    return 0;
}

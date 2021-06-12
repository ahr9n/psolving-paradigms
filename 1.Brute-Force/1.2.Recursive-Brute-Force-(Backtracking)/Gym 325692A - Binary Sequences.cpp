#include <bits/stdc++.h>
 
using namespace std;
 
int t, n;
set<string> s;
 
void bin(string str, int len){
    if(len>n) return;
 
    if(len==n) s.insert(str);
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

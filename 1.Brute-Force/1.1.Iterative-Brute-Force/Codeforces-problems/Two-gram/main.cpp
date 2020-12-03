#include <bits/stdc++.h>

using namespace std;

#define endl            '\n'
#define mem(a , b)      memset(a , b , sizeof(a))
#define repeat(n)       for(int i=0; i<n; i++)
#define NumofDigits(n)  ((int)log10(n)+1)

void quicken(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main(){
    quicken();

    map<string, int> sub;
    int n, maxi=0; cin >> n;
    string str, two; cin >> str;

    for(int i=0; i<str.length()-1; i++)
        if(++sub[str.substr(i, 2)] > maxi) maxi=sub[str.substr(i, 2)], two=str.substr(i, 2);

    return cout << two, 0;
}

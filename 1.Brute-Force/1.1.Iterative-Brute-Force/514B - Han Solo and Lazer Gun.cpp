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

    int n, k=0; cin >> n;
    double x0, y0, x, y; cin >> x0 >> y0;
    set<double> s;
    repeat(n){
        cin >> x >> y;
        if(y!=y0) s.insert((x0-x)/(y0-y)); /// every two points have a slope, and y0-y can't be a zero
        else k = 1; /// only one shot for them all
    }

    cout << s.size()+k;
    return 0;
}

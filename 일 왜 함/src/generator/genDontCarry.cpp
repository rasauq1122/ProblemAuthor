#include "testlib.h"
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main(signed argc, char* argv[]){
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int t = opt<int>("t");
    
    int h = min(n, 40LL);
    
    string s = "";
    for (int i = 0 ; i < n ; i++) {
        s += '1' + (i >= h ? 1 : rnd.next(2));
    }
    
    cout << n << ' ' << t << endl;
    cout << s << endl;
}
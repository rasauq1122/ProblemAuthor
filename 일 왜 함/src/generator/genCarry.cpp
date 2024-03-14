#include "testlib.h"
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main(signed argc, char* argv[]){
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    bool dont = opt<bool>("dont");
    bool fill = opt<bool>("fill");
    
    int h = min(n, 40LL);
    
    string s = "";
    for (int i = 0 ; i < n ; i++) {
        s += '1' + (fill && i >= h ? 1 : rnd.next(2));
    }
    
    int p = 0;
    for (int i = h-1 ; i >= 0 ; i--) {
        p *= 2;
        p += s[i] - '1';
    }
    
    int t = (1LL<<h) - p;
    
    if (t+!dont > 1'000'000'000'000) {
        for (int i = h-1 ; i >= 0 ; i--) if (s[i] == '1') {
            s[i] = '2';
            t -= (1LL<<i);
            if (t+!dont <= 1'000'000'000'000) break;
        }
    } 
    
    cout << n << ' ' << t+!dont << endl;
    cout << s << endl;
}
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    ensure(n%3 == 0);
    
    vector<int> v(n);
    string s = "";
    for (int i = 0 ; i < n ; i++) {
        v[i] = rnd.next(1, 100'000);
        s += 'A' + (i%3);
    }
    
    shuffle(s.begin(), s.end());
    
    int q = opt<int>("q");
    
    cout << n << endl;
    for (int i = 0 ; i < n ; i++) cout << v[i] << " \n"[i+1==n]; 
    cout << s << endl;
    
    cout << q << endl;
    string pat = "213";
    for (int i = 0 ; i < q ; i++) {
        int l = rnd.next(1, n/2);
        int r = rnd.next(n/2, n);
        
        if (l > r) swap(l, r);
        cout << pat[i%3] << ' ' << l << ' ' << r;
        if (pat[i%3] == '1') cout << ' ' << rnd.next(1, 100'000);
        cout << endl;
    }
}
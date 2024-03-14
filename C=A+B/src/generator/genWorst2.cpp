#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    ensure(n%3 == 0);
    ensure(n>3);
    
    vector<int> v(n);
    string s = "";
    for (int i = 0 ; i < n ; i++) {
        v[i] = rnd.next(1, 100'000);
        s += 'A' + (i%3);
    }
    
    shuffle(s.begin()+3, s.end());
    
    int q = opt<int>("q");
    
    cout << n << endl;
    for (int i = 0 ; i < n ; i++) cout << v[i] << " \n"[i+1==n]; 
    cout << s << endl;
    
    cout << q << endl;
    for (int i = 0 ; i < q-1 ; i++) {
        int l = 4;
        int r = n;
        
        cout << 1 << ' ' << l << ' ' <<  r << ' ' << rnd.next(1, 100'000) << '\n';
    }
    cout << "3 4 " << n << endl;
}
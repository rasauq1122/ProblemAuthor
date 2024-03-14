#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    ensure(n%3 == 0);
    
    vector<int> v(n);
    string s = "";
    string abc = "ABC";
    shuffle(abc.begin(), abc.end());
    
    for (int i = 0 ; i < n ; i++) {
        v[i] = rnd.next(1, 100'000);
        s += abc[i%3];
    }
    
    cout << n << endl;
    for (int i = 0 ; i < n ; i++) cout << v[i] << " \n"[i+1==n]; 
    cout << s << endl;
    
    int q = opt<int>("q");
    cout << q << endl;
    string pat = "12";
    for (int i = 0 ; i < q-1 ; i++) {
        int l = rnd.next(1, n/2);
        int r = rnd.next(n/2+1, n);
        
        if (pat[i%2] == '2') r = l+2;
        
        cout << pat[i%2] << ' ' << l << ' ' << r;
        if (pat[i%2] == '1') cout << ' ' << rnd.next(1, 100'000);
        
        cout << '\n';
    }
    
    cout << "3 1 " << n << endl;
}
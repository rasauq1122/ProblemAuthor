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
    ensure(q <= n/3);
    cout << q << endl;
    for (int i = 0 ; i < q ; i++) {
        cout << "3 " << i*3+1 << ' ' << i*3+3 << '\n';
    }
}
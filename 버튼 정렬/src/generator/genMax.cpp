#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = 100'000;
    int w = opt<int>("w");
    vector<int> v(n);
    
    for (int i = 0 ; i < n ; i++) v[i] = rnd.wnext(1, 1'000'000'000, w);
    
    long long q = 1'000'000'000'000'000'000;
    
    cout << n << '\n';
    cout << v[0];
    for (int i = 1 ; i < n ; i++) cout << ' ' << v[i];
    cout << '\n';
    cout << q << '\n';
}
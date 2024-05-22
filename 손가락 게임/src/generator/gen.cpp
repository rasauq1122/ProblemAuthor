#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int a = opt<int>("a");
    int b = opt<int>("b");
    
    cout << a << ' ' << b << '\n';
}

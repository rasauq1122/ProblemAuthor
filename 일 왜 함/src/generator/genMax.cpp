#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    long long t = 1'000'000'000'000;
    
    cout << n << ' ' << t << endl;
    for (int i = 0 ; i < n ; i++) cout << '1';
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    for (int i = 1 ; i < n ; i++) k /= 2;
    cout << k << '\n';
}
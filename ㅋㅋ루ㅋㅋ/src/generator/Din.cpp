#include <bits/stdc++.h>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> uid(0,1);
    
    int n;
    cin >> n;

    freopen((to_string(n)+".in").c_str(), "w", stdout);

    n *= 150000;

    for (int i = 0 ; i < n ; i++) {
        if (uid(gen)) cout << 'K';
        else cout << 'R';
    }
}
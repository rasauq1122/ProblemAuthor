#include <bits/stdc++.h>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> uid(1,INT32_MAX);
    
    char c;
    cin >> c;

    int no;
    cin >> no;

    freopen((c+to_string(no)+".in").c_str(), "w", stdout);

    int n = uid(gen);
    uniform_int_distribution<int> uid2(0,n);

    int p = uid2(gen);

    cout << n << ' ' << 1LL*(n-p+1)*(p+1) - ((c == 'n') ? 2 : 0) << '\n';
}
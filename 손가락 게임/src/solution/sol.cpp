#include <bits/stdc++.h>
using namespace std;

bool is_rsp(int k) {
    return k == 0 || k == 2 || k == 5;
}

int rival(int k) {
    if (k == 0) return 5;
    if (k == 2) return 0;
    if (k == 5) return 2;
    return -1;
}

int main() {
    int a, b;
    char c;
    cin >> a >> b;
    
    if (is_rsp(a) && is_rsp(b)) {
        if (a == b) c = '=';
        else if (rival(a) == b) c = '<';
        else c = '>';
    }
    else if (is_rsp(a) != is_rsp(b)) c = (is_rsp(a) ? '>' : '<');
    else c = '=';
    
    cout << c << endl;
}
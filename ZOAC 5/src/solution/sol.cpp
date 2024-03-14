#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.size();
    s += '?';
    for (int i = 0 ; i < len ;) if (s[i] != s[++i]) return cout << i, 0;
}
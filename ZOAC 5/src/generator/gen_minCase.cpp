#include <bits/stdc++.h>
using namespace std;

const string caseName = "minCase";
const int caseNum = 5; 

int main() {
    random_device rand;
    mt19937 seed(rand());

    vector<int> v(26);
    for (int i = 0 ; i < 26 ; i++) v[i] = i;

    shuffle(v.begin(), v.end(), seed);

    for (int i = 0 ; i < caseNum ; i++) {
        string nowCase = caseName + to_string(i);
        string inCase = nowCase + ".in";
        string outCase = nowCase + ".out";
        freopen(inCase.c_str(), "w", stdout);
        cout << (char)('A'+v[i]) << '\n';
        freopen(outCase.c_str(), "w", stdout);
        cout << 1 << '\n';
    }
}
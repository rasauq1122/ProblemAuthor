#include <bits/stdc++.h>
using namespace std;

const string caseName = "randCase";
const int caseNum = 10; 

int main() {
    random_device rand;
    mt19937 seed(rand());
    uniform_int_distribution<int> gen(1, 26);

    vector<int> v(26);
    for (int i = 0 ; i < 26 ; i++) v[i] = i;

    for (int i = 0 ; i < caseNum ; i++) {
        string nowCase = caseName + to_string(i);
        string inCase = nowCase + ".in";
        string outCase = nowCase + ".out";
        
        int abc = gen(seed);
        uniform_int_distribution<int> gen2(1, 1000000/abc);
        
        int n = gen2(seed);

        freopen(inCase.c_str(), "w", stdout);
        shuffle(v.begin(), v.end(), seed);
        for (int j = 0 ; j < abc ; j++) {
            for (int k = 0; k < n ; k++) cout << (char)('A'+v[j]);
        }
        cout << '\n';

        freopen(outCase.c_str(), "w", stdout);
        cout << n << '\n';
    }
}
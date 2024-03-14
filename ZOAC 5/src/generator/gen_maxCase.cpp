#include <bits/stdc++.h>
using namespace std;

const string caseName = "maxCase";
const int caseNum = 3; 

int main() {
    random_device rand;
    mt19937 seed(rand());

    vector<int> v(26);
    for (int i = 0 ; i < 26 ; i++) v[i] = i;

    for (int i = 0 ; i < caseNum ; i++) {
        string nowCase = caseName + to_string(i);
        string inCase = nowCase + ".in";
        string outCase = nowCase + ".out";

        freopen(inCase.c_str(), "w", stdout);
        shuffle(v.begin(), v.end(), seed);
        for (int j = 0 ; j < 25 ; j++) {
            for (int k = 0; k < 1000000/25 ; k++) cout << (char)('A'+v[j]);
        }
        cout << '\n';

        freopen(outCase.c_str(), "w", stdout);
        cout << (1000000/25) << '\n';
    }

    for (int i = caseNum ; i < 2*caseNum ; i++) {
        string nowCase = caseName + to_string(i);
        string inCase = nowCase + ".in";
        string outCase = nowCase + ".out";

        freopen(inCase.c_str(), "w", stdout);
        shuffle(v.begin(), v.end(), seed);
        for (int j = 0 ; j < 5 ; j++) {
            for (int k = 0; k < 1000000/5 ; k++) cout << (char)('A'+v[j]);
        }
        cout << '\n';

        freopen(outCase.c_str(), "w", stdout);
        cout << (1000000/5) << '\n';
    }
    
    shuffle(v.begin(), v.end(), seed);
    for (int i = 2*caseNum ; i < 3*caseNum ; i++) {
        string nowCase = caseName + to_string(i);
        string inCase = nowCase + ".in";
        string outCase = nowCase + ".out";

        freopen(inCase.c_str(), "w", stdout);
        for (int k = 0; k < 1000000 ; k++) cout << (char)('A'+v[i%26]);
        
        cout << '\n';

        freopen(outCase.c_str(), "w", stdout);
        cout << (1000000) << '\n';
    }
}
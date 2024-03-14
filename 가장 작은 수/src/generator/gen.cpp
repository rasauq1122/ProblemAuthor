#include <bits/stdc++.h>
using namespace std;

const int mod = 2000003;
typedef pair<int,int> pii;

bool npri[2000004];
vector <int> pri;

int pow(int a, int b) {
    if (!b) return 1;
    if (b%2) return (1LL*a*pow(a,b-1))%mod;
    int ret = pow(a, b/2);
    return (1LL*ret*ret)%mod;
}

bool cmp(pii a, pii b) {
    return a.second*log(a.first) > b.second*log(b.first);
}

int arr[111223], caseNum = 0;

int main() {
    random_device rand;
    mt19937 seed(rand());

    for (int i = 2 ; i <= 2000003 ; i++) if (!npri[i]) {
        pri.push_back(i);
        for (int j = 2*i ; j <= 2000003 ; j += i) npri[j] = true;
    }

    priority_queue<pii, vector<pii>, decltype(&cmp)> pq(cmp);

    int len = (int)pri.size();
    for (int i = 0 ; i < len ; i++) pq.push({pri[i], 1});

    int ans = 1;
    for (int i = 0 ; i <= 111222 ; i++) {
        auto [p, k] = pq.top();
        arr[i] = ans;
        pq.pop();

        ans = (1LL*ans*pow(p, k))%mod;
        pq.push({p, 2*k});
    }

    for (int i = 2 ; i <= 9 ; i++) {
        string caseName = "N_equals_" + to_string(i);
        string inCase = caseName + ".in";
        string outCase = caseName + ".out"; 

        freopen(inCase.c_str(), "w", stdout);
        cout << i << '\n';

        freopen(outCase.c_str(), "w", stdout);
        cout << arr[i] << '\n';
    }

    for (int i = 0 ; i < 10 ; i++) {
        
        uniform_int_distribution<int> gen(10, 99);

        int k = gen(seed);
        string caseName = "N_equals_" + to_string(k);
        string inCase = caseName + ".in";
        string outCase = caseName + ".out"; 

        freopen(inCase.c_str(), "w", stdout);
        cout << k << '\n';

        freopen(outCase.c_str(), "w", stdout);
        cout << arr[k] << '\n';
    }    

    for (int i = 0 ; i < 20 ; i++) {
        
        uniform_int_distribution<int> gen(100, 999);

        int k = gen(seed);
        string caseName = "N_equals_" + to_string(k);
        string inCase = caseName + ".in";
        string outCase = caseName + ".out"; 

        freopen(inCase.c_str(), "w", stdout);
        cout << k << '\n';

        freopen(outCase.c_str(), "w", stdout);
        cout << arr[k] << '\n';
    }    

    for (int i = 0 ; i < 30 ; i++) {
        
        uniform_int_distribution<int> gen(1000, 9999);

        int k = gen(seed);
        string caseName = "N_equals_" + to_string(k);
        string inCase = caseName + ".in";
        string outCase = caseName + ".out"; 

        freopen(inCase.c_str(), "w", stdout);
        cout << k << '\n';

        freopen(outCase.c_str(), "w", stdout);
        cout << arr[k] << '\n';
    }    

    for (int i = 0 ; i < 40 ; i++) {
        
        uniform_int_distribution<int> gen(10000, 99999);

        int k = gen(seed);
        string caseName = "N_equals_" + to_string(k);
        string inCase = caseName + ".in";
        string outCase = caseName + ".out"; 

        freopen(inCase.c_str(), "w", stdout);
        cout << k << '\n';

        freopen(outCase.c_str(), "w", stdout);
        cout << arr[k] << '\n';
    }    

    for (int i = 0 ; i < 10 ; i++) {
        
        uniform_int_distribution<int> gen(100000, 111221);

        int k = gen(seed);
        string caseName = "N_equals_" + to_string(k);
        string inCase = caseName + ".in";
        string outCase = caseName + ".out"; 

        freopen(inCase.c_str(), "w", stdout);
        cout << k << '\n';

        freopen(outCase.c_str(), "w", stdout);
        cout << arr[k] << '\n';
    }    

    string caseName = "N_equals_111222";
    string inCase = caseName + ".in";
    string outCase = caseName + ".out"; 

    freopen(inCase.c_str(), "w", stdout);
    cout << 111222 << '\n';

    freopen(outCase.c_str(), "w", stdout);
    cout << arr[111222] << '\n';
}
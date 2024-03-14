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

int main() {
    int n;
    cin >> n;

    for (int i = 2 ; i <= 2000003 ; i++) if (!npri[i]) {
        pri.push_back(i);
        for (int j = 2*i ; j <= 2000003 ; j += i) npri[j] = true;
    }

    priority_queue<pii, vector<pii>, decltype(&cmp)> pq(cmp);

    int len = (int)pri.size();
    for (int i = 0 ; i < len ; i++) pq.push({pri[i], 1});

    int ans = 1;
    for (int i = 0 ; i < n ; i++) {
        auto [p, k] = pq.top();
        pq.pop();

        ans = (1LL*ans*pow(p, k))%mod;
        pq.push({p, 2*k});
    }

    cout << ans << endl;
}
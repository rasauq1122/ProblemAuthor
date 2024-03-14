#include <bits/stdc++.h>
#include <random>

#define prt(V)          {for(int NI=0;NI<(V).size();NI++){cout<<(V[NI])<<' ';}cout<<'\n';}
#define prt2(V)         {for(int NI=0;NI<(V).size();NI++){for(int NJ=0;NJ<(V[NI]).size();NJ++){cout<<V[NI][NJ]<<' ';}cout<<'\n';}}

#define pf0()           cout<<'\n'
#define pf1(x)          cout<<' '<<(x)<<'\n'
#define pf2(x,y)        cout<<' '<<(x)<<' '<<(y)<<'\n'
#define pf3(x,y,z)      cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<'\n'
#define pf4(x,y,z,w)    cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<'\n'
#define pf5(x,y,z,w,u)  cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<' '<<(u)<<'\n'

#define TC()            int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define FASTIO()        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fixed(a)        cout<<fixed;cout.precision(a);

#define endl            '\n'
#define blk             ' '
#define pii             pair<int,int>
#define ff              first
#define ss              second
#define vi              vector<int>
#define vp              vector<pair<int,int>>
#define wi              vector<vector<int>>
#define wp              vector<vector<pair<int,int>>>
#define pb              push_back
#define all(v)          (v).begin(), (v).end()
#define INF             ((1LL<<31)-1)
#define MOD             1000000007

using namespace std;

int main() {
    for (int tc = 1 ; tc <= 30 ; tc++) {
        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<int> uid(0,1);
        
        int n;
        n = 20;

        freopen(("sml"+to_string(tc)+".in").c_str(), "w", stdout);
        

        for (int i = 0 ; i < n ; i++) {
            cout << (uid(gen) ? 'K' : 'R');
        }
        
        cout << endl;
    }

    for (int tc = 1 ; tc <= 30 ; tc++) {
        freopen(("sml"+to_string(tc)+".out").c_str(), "w", stdout);
        freopen(("sml"+to_string(tc)+".in").c_str(), "r", stdin);

        string s;
        cin >> s;

        int r = 0, len = s.size();
        for (int i = 0 ; i < len ; i++) {
            r += s[i] == 'R';
        }

        int k1 = 0, k2 = 0, i = 0, j = len-1, da = r;

        while (true) {
            bool chk1 = k1 <= k2, chk2 = k1 >= k2; 
            
            if (r <= 0) {
                break;
            }

            if (chk1) {
                while (s[i] == 'K') {
                    k1++;
                    i++;
                }
            }
            
            if (chk2) {
                while (s[j] == 'K') {
                    k2++;
                    j--;
                }
            }

            da = max(da, r + 2*min(k1, k2));
            
            if (k1 <= k2) {
                r--;
                i++;
            }

            if (k2 <= k1) {
                r--;
                j--;
            }

            if (i >= j) {
                break;
            }
        }

        cout << da;
    }
}
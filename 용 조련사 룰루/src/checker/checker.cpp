#include <bits/stdc++.h>
using namespace std;

char buffer[1000000];

string read_string(FILE *fp) {
    assert(fscanf(fp,"%10000s",buffer)==1);
    return string(buffer);
}

int read_int(FILE *fp) {
    int temp;
    assert(fscanf(fp,"%d",&temp)==1);
    return temp;
}

int n, m;
vector<int> v, p, srt;

int lim_idx[1000000];
bool chk_permutation[1000001];
bool moved[1000001];
bool check_fail() {
    for (int i = 0 ; i < n ; i++) srt.push_back(v[i]);
    sort(srt.begin(), srt.end());

    for (int i = 0 ; i < min(3, n-1) ; i++) {
        if (srt[n-1-i] - srt[n-2-i] > m) return true; 
    }

    return false;
}

int main(int argc, char *argv[]) {
    FILE *in = fopen(argv[1], "r");
    FILE *sol = fopen(argv[2], "r"); 
    FILE *out = fopen(argv[3], "r");
    
    n = read_int(in); 
    m = read_int(in);

    for (int i = 0 ; i < n ; i++) {
        int x = read_int(in);
        v.push_back(x);
    }

    string s = read_string(out);
    assert(s == "YES" || s == "NO");
    bool chk = check_fail();
    if (s == "YES") {
       
        for (int i = 0 ; i < n ; i++) {
            int x = read_int(out);
            assert(1 <= x && x <= n);
            assert(!chk_permutation[x]);
            chk_permutation[x] = true;
            p.push_back(x);
        }

        int b_max = 0;
        int a_cnt = 0;
        int a_idx = n-1;
        
        for (int i = 0 ; i < n ; i++) lim_idx[i] = lower_bound(srt.begin(), srt.end(), srt[i]-m) - srt.begin();
        
        for (int i = 0 ; i < n ; i++) {
            int now = v[p[i]-1];
            if (i) {
                assert(now <= b_max + m);
                if (i == 1 && now < b_max) assert(b_max <= now + m);
                b_max = max(b_max, now);
            }
            else b_max = now;
            
            if (i < n-2) {
                int p_idx = lower_bound(srt.begin(), srt.end(), now) - srt.begin();
                if (p_idx == a_idx) {
                    int nlim = lim_idx[a_idx];
                    for ( ; moved[--a_idx] ; a_cnt--);
                    for (int j = nlim-1 ; j >= lim_idx[a_idx] ; j--) a_cnt += moved[j];
                    assert(a_cnt < a_idx - lim_idx[a_idx]);
                }
                else {
                    moved[p_idx] = true;
                    if (lim_idx[a_idx] <= p_idx) {
                        a_cnt++;
                        assert(a_cnt < a_idx - lim_idx[a_idx]);
                    }
                }
            }
        }
        int temp;
        assert(fscanf(out,"%d",&temp)!=1);
    }
    else assert(chk);
}
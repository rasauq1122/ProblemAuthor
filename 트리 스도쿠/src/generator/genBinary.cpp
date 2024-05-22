#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
vector<pair<int,int>> child;
 
int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int treetype = opt<int>("treetype");
    bool arrayRandom = opt<bool>("arrayRandom");
    bool arrayMin = opt<bool>("arrayMin");
    bool arrayMax = opt<bool>("arrayMax");
    bool arrayShuffle = opt<bool>("arrayShuffle");
    ensure(n%2);
    
    child = vector<pair<int, int>>(n/2);
    
    vector<int> cardinal(n/2+1);
    for (int i = 0 ; i < n/2+1 ; i++) cardinal[i] = i;
    
    vector<int> nonleaf(n/2);
    for (int i = 0 ; i < n/2 ; i++) nonleaf[i] = i;
    
    shuffle(cardinal.begin(), cardinal.end());
    shuffle(nonleaf.begin(), nonleaf.end());
    
    for (int i = 0 ; i < n/2 ; i++) {
        child[nonleaf[i]] = {cardinal[i*2], cardinal[i*2+1]};
        if (i+1 == n/2) break;
        cardinal.push_back(nonleaf[i]+n/2+1);
        if (treetype == 0) // random
            swap(cardinal[i+n/2], cardinal[rnd.next(i*2+2, i+n/2)]); 
        else if (treetype == 1) // skew
            swap(cardinal[i+n/2], cardinal[i*2+2]);
        else if (treetype == 2) // full-binary
            ; // do nothing
        else
            ensure(false);
    }
    
    cout << n << endl;
    vector <int> arr(n);
    
    if (arrayRandom) {
        for (int i = 0 ; i < n ; i++) arr[i] = rnd.next(-1'000'000'000, 1'000'000'000);
        sort(arr.begin(), arr.end());
        
        for (int i = 1 ; i < n ; i++) {
            while (arr[i-1] >= arr[i]) arr[i]++;
        }
    }
    else {
        if (arrayMin)
            for (int i = 0 ; i < n ; i++) arr[i] = -1'000'000'000 + i;
        else if (arrayMax) 
            for (int i = 0 ; i < n ; i++) arr[i] = (1'000'000'000 - (n-1)) + i;
        else 
            for (int i = 0 ; i < n ; i++) arr[i] = -n/2 + i;
    }
    
    if (arrayShuffle) shuffle(arr.begin(), arr.end());

    for (int i = 0 ; i < n ; i++) {
        cout << arr[i] << " \n"[i+1==n];
    }
    
    for (int i = 0 ; i < n/2 ; i++) {
        auto [l, r] = child[i];
        cout << i+n/2+2 << ' ' << l+1 << endl;
        cout << i+n/2+2 << ' ' << r+1 << endl;
    }
}

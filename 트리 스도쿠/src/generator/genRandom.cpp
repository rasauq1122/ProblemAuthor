#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
vector<pair<int,int>> child;
 
int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int treetype = opt<int>("treetype");
    int k = opt<int>("arrayRange");
    bool arrayRandom = opt<bool>("arrayRandom");
    bool arrayMin = opt<bool>("arrayMin");
    bool arrayMax = opt<bool>("arrayMax");
    bool arrayShuffle = opt<bool>("arrayShuffle");
    
    vector<int> node(n);
    for (int i = 0 ; i < n ; i++) node[i] = i+1;
    shuffle(node.begin(), node.end());
    
    cout << n << endl;
    vector <int> arr(n);
    if (arrayRandom) {
        ensure(n <= 2*k+1);
        for (int i = 0 ; i < n ; i++) arr[i] = rnd.next(-k, k);
        sort(arr.begin(), arr.end());
        
        arr[0] = min(k - (n-1), arr[0]);
        
        for (int i = 1 ; i < n ; i++) {
            if (arr[i-1] >= arr[i]) arr[i] = arr[i-1] + 1;
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
    
    for (int i = 1 ; i < n ; i++) {
        int r = node[i];
        int lidx;
        if (treetype == 0) // random
            lidx = rnd.next(0, i-1);
        else if (treetype == 1) // skew
            lidx = i-1;
        else if (treetype == 2) // star
            lidx = 0;
        else 
            ensure(false);
        int l = node[lidx];
        
        if (rnd.next(2)) cout << l << ' ' << r << '\n';
        else cout << r << ' ' << l << '\n';
    }
    
}

// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 09:11:20, 19/04/2025
// https://cses.fi/problemset/task/2163
// --------------------------------
#include <iostream>
#include <set>
#include <cmath>
#include <fstream>

using namespace std;

class FenwickTree {
public:
    int N;
    int *bit;

    FenwickTree(){
        N = 0;
        bit = nullptr;
    }
    FenwickTree(int size){
        N = size;
        bit = new int[N + 1];
        for (int i = 1; i <= N; i++){
            update(i, 1);
        }
    }

    int getSum(int p) {
        int idx = p, ans = 0;
        while (idx > 0) {
            ans += bit[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }

    void update(int u, int v) { // pos u; value v
        int idx = u;
        while (idx <= N) {
            bit[idx] += v;
            idx += (idx & (-idx));
        }
    }

    int findKth(int k){
        int lo = 1, hi = N;
        while (lo < hi){
            int mid = (hi + lo)/2;
            if (getSum(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }

    ~FenwickTree(){
        delete []bit;
    }
};

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream file("input.txt");
    if (file.good()){
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    }
    
    int N, k; cin >> N >> k;
    
    FenwickTree tree(N);
    int alive = N, currPos = 0;

    for (int i = 0; i < N; i++){
        currPos = (currPos + k) % alive;
        int pos = tree.findKth(currPos + 1);
        cout << pos << " ";
        tree.update(pos, -1);
        alive--;
    }
}

int main() {
    solve();
    return 0;
}
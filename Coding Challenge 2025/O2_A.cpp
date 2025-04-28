// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 21:01:23, 26/04/2025
// O2_A Coding Challenge 2025 @ FIT-HCMUS
// --------------------------------
#include <iostream>

using namespace std;

int getFast(const int* v, const int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += v[i];
    }
    return sum;
}

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, k; cin >> n >> k;
    int v[2*n];
    for (int i = 0; i < n; i++){
        v[i] = 1;
    }
    for (int i = n; i < 2 * n; i++){
        v[i] = 0;
    }
    int a, b;
    while (k--){
        cin >> a >> b;
        swap(v[a - 1], v[b - 1]);
        cout << getFast(v, n) << "\n";
    }

}

int main() {
    solve();
    return 0;
}
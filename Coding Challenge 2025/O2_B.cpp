// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 21:13:23, 26/04/2025
// O2_B Coding Challenge 2025 @ FIT-HCMUS
// --------------------------------
#include <iostream>

using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t; cin >> t;
    int a, b, c;
    bool check = true;
    while (t--){
        cin >> a >> b >> c;
        check = (a%3 == b%3) || (b%3 == c%3) || (a%3 == c%3);
        cout << (check ? "YES\n" : "NO\n");
    }
}

int main() {
    solve();
    return 0;
}
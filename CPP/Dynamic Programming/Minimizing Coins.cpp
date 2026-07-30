// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 18:02:54, 09/08/2025
// https://cses.fi/problemset/task/1634
// --------------------------------
#include <iostream>
#include <vector>

using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, x; cin >> n >> x;
    vector<int> a(n);
    vector<int> dp(1000001, -1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        dp[a[i]] = 1;
    }
    dp[0] = 0;
    
    for (int i = 1; i <= x; i++){
        if (dp[i] != -1) continue; // defined -> continue
        int pre = -1;
        for (int j = 0; j < n; j++){
            if (i < a[j]) continue;
            if (dp[i - a[j]] != -1){
                if (pre != -1) {
                    pre = min(pre, dp[i - a[j]]);
                } else {
                    pre = dp[i - a[j]];
                }
            }
        }
        if (pre != -1) dp[i] = pre + 1;
    }
    // for (int i = 0; i <= x; i++){
    //     cout << dp[i] << " ";
    // } cout << "\n";
    cout << dp[x];
}

int main() {
    solve();
    return 0;
}
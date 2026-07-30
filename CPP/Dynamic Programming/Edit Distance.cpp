// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 23:23:00, 24/09/2025
// https://cses.fi/problemset/task/1639/
// --------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

typedef long long ll;

using namespace std;


void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // dp[i][j]: Levenshtein_distance between a[0..i-1] and b[0..j-1]
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <=m; j++){
            int cost = 1;
            if (a[i-1] == b[j-1]) cost = 0;
            dp[i][j] = min({
                dp[i-1][j] + 1, // deletion
                dp[i][j-1] + 1, // insertion
                dp[i-1][j-1] + cost // substitution
            });
        }
    }
    cout << dp[n][m] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // int t; cin >> t;
    // while (t--){
    //     solve();
    // }

    solve();
    return 0;
}
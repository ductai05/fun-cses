// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 17:10:43, 21/08/2025
// https://cses.fi/problemset/task/1638
// --------------------------------
#include <iostream>
#include <vector>

using namespace std;

void readTable(int** table, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << table[i][j];
        }
        cout << "\n";
    }
}

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // if (!freopen("input.txt", "r", stdin)) return;
    // freopen("output.txt", "w", stdout);
    int MOD = 1000000007;
    int n; cin >> n;
    int** table = new int* [n + 1];
    for (int i = 0; i < n; i++)
        table[i] = new int[n + 1]();

    string line;
    for (int row = 0; row < n; row++){
        cin >> line;
        for (int col = 0; col < n; col++){
            if (line[col] == '*'){
                table[row][col] = 1;
            }
        }
    }

    // readTable(table, n);
    
    int** dp = new int* [n + 1];
    for (int i = 0; i < n; i++)
        dp[i] = new int[n + 1]();

    if (!table[0][0]) dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (table[i][j]) continue;
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n - 1][n - 1];
}

int main() {
    solve();
    return 0;
}
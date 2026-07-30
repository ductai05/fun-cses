// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 09:22:59, 26/10/2025
// https://cses.fi/problemset/task/1624
// --------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

typedef long long ll;

using namespace std;

bool check(const vector<pair<int,int>>& queens, pair<int, int>& new_queens){
    for (pair<int, int> p : queens){
        if (new_queens.first == p.first) return false;
        if (abs(new_queens.first - p.first) == abs(new_queens.second - p.second)) return false;
    }
    return true;
}

void copy(const vector<pair<int,int>>& queens, vector<pair<int,int>>& cur_queens){
    int queens_size = queens.size();
    for (int i = 0; i < queens_size; i++){
        cur_queens[i] = queens[i];
    }
}

int possible_ways(vector<vector<int>>& blocked, const vector<pair<int,int>>& queens, 
    int start_col, pair<int, int> new_queens = {-1, -1}){
    vector<pair<int,int>> cur_queens(queens.size());
    if (start_col != 0){
        if (check(queens, new_queens)){
            copy(queens, cur_queens);
            cur_queens.push_back(new_queens);
        } else return 0;
    }
    if (cur_queens.size() >= 8) return 1;
    int ans = 0;
    for (int row = 0; row < 8; row++){
        if (blocked[row][start_col]) continue;
        ans += possible_ways(blocked, cur_queens, start_col + 1, {row, start_col});
    }
    // cout << "start_col: " << start_col << "; ans: " << ans << "\n";
    return ans;
}

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<vector<int>> blocked(8, vector<int>(8, 0));
    vector<pair<int,int>> queens(0);

    char c;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> c;
            if (c == '*') blocked[i][j] = 1;
        }
    }
    // for (int i = 0; i < 8; i++){
    //     for (int j = 0; j < 8; j++){
    //         cout << blocked[i][j] << " ";
    //     } cout << "\n";
    // }

    cout << possible_ways(blocked, queens, 0);
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
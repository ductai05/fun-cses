// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 18:08:14, 29/04/2025
// https://cses.fi/problemset/task/1641
// --------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, x; cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        return a.first < b.first;
    });
    unordered_map<int, pair<int, int>> sums;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int sum = v[i].first + v[j].first;
            if (sums.find(sum) == sums.end()){
                sums[sum] = {i, j};
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int to_find = x - v[i].first - v[j].first;
            if (to_find < 0) continue;
            if (sums.find(to_find) != sums.end()){
                pair<int, int> a = sums[to_find];
                if (a.first == i || a.first == j || a.second == i || a.second == j){
                    continue;
                }
                cout << v[i].second << " " << v[j].second << " "
                     << v[a.first].second << " " << v[a.second].second;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    solve();
    return 0;
}
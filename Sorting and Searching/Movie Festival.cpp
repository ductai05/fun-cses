// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 16:17:11, 18/04/2025
// https://cses.fi/problemset/task/1629
// --------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
void solve(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n; cin >> n;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++){
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });
    int end = 0, res = 0;
    for (auto it : movies){
        if (it.first >= end){
            res++;
            end = it.second;
        }
    }
    cout << res;
}
 
int main() {
    solve();
    return 0;
}

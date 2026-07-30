// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 17:48:26, 29/04/2025
// https://cses.fi/problemset/task/1641
// --------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool binary_search(const vector<pair<int, int>> &v, int n, int x, int &index){
    int lo = 0, hi = n - 1;
    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if (v[mid].first == x){
            index = mid;
            return true;
        } else if (v[mid].first < x){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return false;
}
 
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
 
    int index = -1;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (x - v[i].first - v[j].first < 0) continue;
            if (binary_search(v, n, x - v[i].first - v[j].first, index)){
                if (index == i || index == j) continue;
                cout << v[i].second << " " << v[j].second << " " << v[index].second;
                // cout << "\n" << index;
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

// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 19:13:11, 18/04/2025
// https://cses.fi/problemset/task/1073
// --------------------------------
#include <iostream>
#include <set>

using namespace std;

void solve(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    multiset<int> ms;
    int n, x; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        auto it = ms.upper_bound(x);
        if (it != ms.end()) ms.erase(it);
        ms.insert(x);
    }
    cout << ms.size();
}

int main() {
    solve();
    return 0;
}
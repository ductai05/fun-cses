// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 07:45:29, 19/04/2025
// https://cses.fi/problemset/task/1163
// --------------------------------
#include <iostream>
#include <set>
#include <cmath>
 
using namespace std;
 
void solve(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    int x, n; cin >> x >> n;
    set<int> light{0, x};
    multiset<int> dist{x};
    int temp;
    for (int i = 0; i < n; i++){
        cin >> temp;
        auto it = light.upper_bound(temp); //*it > temp
        auto it2 = it; it2--;
        dist.erase(dist.find(*it - *it2));
        dist.insert(*it - temp);
        dist.insert(temp - *it2);
        light.insert(temp);
 
        auto res = dist.end();
        cout << *(--res) << " ";
    }
}
 
int main() {
    solve();
    return 0;
}

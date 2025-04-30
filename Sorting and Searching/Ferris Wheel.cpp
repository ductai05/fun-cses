#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <unordered_map>
#include <set>
using namespace std;
 
void solve(){
    int n, x; cin >> n >> x;
    int *p = new int [n];
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);
    int ans = 0, top = n - 1, bot = 0;
    while (top > bot){
        if (p[top] + p[bot] <= x){
            ans++; top--; bot++;
        } else {
            top--; ans++;
        }
    }
    if (top == bot) ans += 1;
    cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

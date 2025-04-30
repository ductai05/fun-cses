// cieldt - AI23@HCMUS
 
#include <iostream>
#include <algorithm> 
// #include <vector>
// #include <string>
// #include <unordered_map>
// #include <set>
#define F first
#define S second
typedef long long ll;
using namespace std;
 
void solve(){
    int n;
    cin >> n;
 
    int* a = new int [n];
    int* pos = new int [n + 1];
 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
 
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (pos[i] < pos[i - 1]) {
            ans++;
        }
    }
    cout << ans;
    delete []a;
    delete []pos;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// cieldt - AI23@HCMUS
 
#include <iostream>
// #include <algorithm> 
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
    
    int* p = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
 
    ll min_diff = -1; 
 
    for (int i = 0; i < (1 << n); ++i) {
        ll group1_sum = 0;
        ll group2_sum = 0;
 
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) { 
                group2_sum += p[j];
            } else {
                group1_sum += p[j];
            }
        }
 
        ll diff = abs(group1_sum - group2_sum);
        if (min_diff == -1 || diff < min_diff) {
            min_diff = diff;
        }
    }
 
  cout << min_diff << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

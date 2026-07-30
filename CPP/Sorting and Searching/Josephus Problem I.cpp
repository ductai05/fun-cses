// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 08:41:16, 19/04/2025
// https://cses.fi/problemset/task/2162
// --------------------------------
#include <iostream>
#include <queue>
 
using namespace std;
 
void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
 
    bool remove = false;
    while (!q.empty()){
        int ele = q.front();
        q.pop();
        if (remove){
            cout << ele << " ";
        } else {
            q.push(ele);
        }
        remove = !remove;
    }
}
 
int main() {
    solve();
    return 0;
}

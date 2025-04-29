// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 15:08:16, 21/04/2025
// https://cses.fi/problemset/task/2165
// --------------------------------
#include <iostream>
#include <cmath>
 
using namespace std;
 
void move(int n, int from, int mid, int to){
    if (n == 1){
        cout << from << " " << to << "\n";
        return;
    }
    move(n - 1, from, to, mid); // move n - 1 ele A -> B;
    cout << from << " " << to << "\n"; // move last ele A -> C
    move(n - 1, mid, from, to); // move n - 1 ele B -> C
}
 
void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    int n; cin >> n;
    cout << pow(2, n) - 1 << "\n";
    move(n, 1, 2, 3);
}
 
int main() {
    solve();
    return 0;
}

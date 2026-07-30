// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 21:56:08, 30/04/2025
// https://cses.fi/problemset/task/1645
// --------------------------------
#include <iostream>
#include <stack>

using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    stack<pair<int, int>> st;
    int x, loop = n;
    while(loop--){
        cin >> x;
        while(!st.empty() && st.top().first >= x){
            st.pop();
        }
        if (st.empty()){
            cout << "0 ";
        } else {
            cout << st.top().second << " ";
        }
        st.push({x, n - loop});
    }
}

int main() {
    solve();
    return 0;
}
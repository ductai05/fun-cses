// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 21:40:48, 26/04/2025
// O2_C Coding Challenge 2025 @ FIT-HCMUS
// --------------------------------
#include <iostream>

using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i]; 
    }
    // Subtask 2:
    bool subtask_2 = true;
    for (int i = 0; i < n; i++){
        if (a[i] != 0){
            subtask_2 = false;
            break;
        }
    }
    if (subtask_2){
        int res = 1;
        for (int i = 0; i < n; i++){
            cout << res << " ";
            res = ((res == 1) ? 2 : 1);
        }
    } else {
        cout << "impossible"; // :D
    }
}

int main() {
    solve();
    return 0;
}
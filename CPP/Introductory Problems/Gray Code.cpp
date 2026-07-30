// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 00:17:03, 18/04/2025
// https://cses.fi/problemset/task/2205/
// --------------------------------
#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;
 
void solve(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    unordered_set<string> gray_code;
    int n; cin >> n;
    long long lines = pow(2, n);
    string s = "";
    for (int i = 0; i < n; i++) s += "0";
    cout << s << "\n";
    gray_code.insert(s);
    while (lines--){
        int most_sig = n - 1;
        while (most_sig >= 0){
            string change = (s[most_sig] == '0') ? "1" : "0";
            string temp = s;
            temp.replace(most_sig, 1, change);
            if (!gray_code.count(temp)){
                cout << temp << "\n";
                gray_code.insert(temp);
                s = temp;
                break;
            }
            most_sig--;
        }
    }
 
}
 
int main() {
    solve();
    return 0;
}

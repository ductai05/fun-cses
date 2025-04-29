// cieldt - AI23@HCMUS
 
#include <iostream>
#include <algorithm> 
// #include <vector>
// #include <string>
#include <unordered_map>
#include <set>
#define F first
#define S second
typedef long long ll;
using namespace std;
 
int factorial(int a){
    if (a == 1) return 1;
    return a * factorial(a - 1);
}
 
void printStr(set<char> s, int l, unordered_map<char, int> map, string ans){
    if (l == 1){
        for (char c : s){
            if (map[c] > 0){
                ans += c;
                // map[c]--;
            } 
        }
        // cout << l << " ";
        cout << ans << "\n";
        
    } else {
        string newans = ans;
        for (char c : s){
            if (map[c] == 0) continue;
            newans = ans;
            newans += c;
            map[c] -= 1;
                
            printStr(s, l - 1, map, newans);
            
            map[c] += 1;
        }
    }
}
 
void solve(){
    string str; cin >> str;
    
    unordered_map<char, int> map;
    set<char> s;
    int l = str.size();
    // cout << l << ": " << str << "\n";
    
    for (int i = 0; i < l; i++){
        s.insert(str[i]);
        if (map.count(str[i]) == 1){
            map[str[i]] += 1;
        } else {
            map[str[i]] = 1;
        }
    }
    int num_of_strs = factorial(l);
    for (char c : s){
        num_of_strs /= factorial(map[c]);
    }
    cout << num_of_strs << "\n";
    
    // for (char c : s){
        // cout << c << ": " << map[c] << "\n";
    // }
    
    printStr(s, l, map, "");
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
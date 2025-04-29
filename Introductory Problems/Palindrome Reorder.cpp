// cieldt - AI23@HCMUS
 
#include <iostream>
#include <algorithm> 
#include <vector>
// #include <string>
#include <unordered_map>
#include <set>
#define F first
#define S second
typedef long long ll;
using namespace std;
 
int search(int* a, int n, int st, int en, int key){
    int ans = st;
    for (int i = en; i >= st; i--){
        if (a[i] == key){
            ans = i; break; 
        }
    }
    return ans;
}
 
 
void solve(){
    string str; cin >> str;
    // cout << str << "\n";
    
    unordered_map<char, int> map;
    set<char> s;
    int l = str.size();
    for (int i = 0; i < l; i++){
        s.insert(str[i]);
        if (map.count(str[i]) == 1){
            map[str[i]] += 1;
        } else {
            map[str[i]] = 1;
        }
    }
    int no_sol = -1;
    char odd;
    for (char c : s){
        // cout << c << " " << map[c] << "\n";
        if (map[c] % 2 == 1){
            odd = c;
            no_sol++;
        }
    }
    if (no_sol >= 1){
        cout << "NO SOLUTION";
        return;
    }
    
    vector<char> v;
    for (char c : s){
        v.push_back(c);
        if (c != odd){
            int loop = map[c] / 2;
            for (int i = 0; i < loop; i++){
                cout << c;
            }
        }
    }
    
    int loop = map[odd];
    for (int i = 0; i < loop; i++) cout << odd;
    
    l = v.size();
    for (int j = l - 1; j >= 0; j--){
        char c = v[j];
        if (c != odd){
            int loop = map[c] / 2;
            for (int i = 0; i < loop; i++){
                cout << c;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

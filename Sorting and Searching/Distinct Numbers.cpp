#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <unordered_map>
#include <set>
using namespace std;
 
void solve(){
    int n, temp;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        s.insert(temp);
    }
    cout << s.size();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

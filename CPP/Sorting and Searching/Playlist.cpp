// cieldt - AI23@HCMUS
 
#include <iostream>
#include <algorithm> 
// #include <vector>
// #include <string>
// #include <unordered_map>
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
 
void printArray(int* a, int st, int en){
    for (int i = st; i <= en; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
 
void solve(){
    int n;
    cin >> n;
    int* a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int st = 0, en = -1, ans = 1;
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (s.find(a[i]) != s.end()){ // a[i] was found
            int des = search(a, n, st, en, a[i]);
            for (int j = st; j <= des; j++){
                s.erase(a[j]);
            }
            st = des + 1;
        } 
        s.insert(a[i]);
        en++;
        ans = max(ans, en - st + 1);
        // printArray(a, st, en);
    }
    cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

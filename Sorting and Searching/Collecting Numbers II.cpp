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
 
void swapPos(int* &pos, int* &a, int n, int pos1, int pos2, int &ans){
    int numAtPos1 = a[pos1 - 1];
    int numAtPos2 = a[pos2 - 1];
    
    set<pair<int, int>> s;
    if (numAtPos1 > 1) s.insert({numAtPos1 - 1, numAtPos1});
    if (numAtPos1 < n) s.insert({numAtPos1, numAtPos1 + 1});
    if (numAtPos2 > 1) s.insert({numAtPos2 - 1, numAtPos2});
    if (numAtPos2 < n) s.insert({numAtPos2, numAtPos2 + 1});
 
    for (auto p : s) {
        if (pos[p.F] > pos[p.S]) ans--;
    }
 
    swap(pos[numAtPos1], pos[numAtPos2]);
    swap(a[pos1 - 1], a[pos2 - 1]);
 
    for (auto p : s) {
        if (pos[p.F] > pos[p.S]) ans++;
    }
}
 
void swapPosTRAU(int* &pos, int* &a, int n, int pos1, int pos2, int &ans){
    int numAtPos1 = a[pos1 - 1];
    int numAtPos2 = a[pos2 - 1];
    
 
    swap(pos[numAtPos1], pos[numAtPos2]);
    swap(a[pos1 - 1], a[pos2 - 1]);
    
    ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (pos[i] < pos[i - 1]) {
            ans++;
        }
    } // new ans
}
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    int* a = new int [n];
    int* pos = new int [n + 1];
 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    
    int* pos1 = new int [m];
    int* pos2 = new int [m];
    for (int i = 0; i < m; i++){
        cin >> pos1[i] >> pos2[i];
    }
    
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (pos[i] < pos[i - 1]) {
            ans++;
        }
    } // original ans
 
    for (int j = 0; j < m; j++){
        swapPos(pos, a, n, pos1[j], pos2[j], ans);
        cout << ans << "\n";
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

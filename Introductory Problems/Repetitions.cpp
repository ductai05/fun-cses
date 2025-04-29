#include<iostream>
 
using namespace std;
 
int main(){
    string s; cin >> s;
    int n = s.size();
    int ans = 1; int now = 1;
    for (int i = 1; i < n; i++){
        if (s[i] == s[i - 1]) now += 1;
        else {
            ans = max(ans, now);
            now = 1;
        }
    }
    ans = max(ans, now);
    cout << ans;
}
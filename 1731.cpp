// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 20:20:34, 17/04/2025
// https://cses.fi/problemset/task/1731/
// --------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
// #include <algorithm>
using namespace std;
#define modulo 1000000007

class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool is_end;

    TrieNode(){
        is_end = false;
    }
    friend class Trie;
};

class Trie {
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        for (char c : word){
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_end = true;
    }
};

void solve(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    Trie dict;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++){
        string word;
        cin >> word;
        dict.insert(word);
    }

    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; i++){
        if (dp[i] == 0) continue;
        TrieNode* cur = dict.root;
        for (int j = i; j < n; j++){
            char c = s[j];
            if (cur->children.find(c) == cur->children.end()) break;
            cur = cur->children[c];
            if (cur->is_end){
                dp[j + 1] += dp[i];
                dp[j + 1] %= modulo;
            }
        }
    }
    cout << dp[n];
}

int main() {
    solve();
    return 0;
}
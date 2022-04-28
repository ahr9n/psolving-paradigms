#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O2")

using namespace std;

const int N = 1e4 + 5, M = 1e5 + 5, MAX_NODES = 26;

int n, m;
string s, temp;
string words[M];

vector<int> ans;
int memo[N];

struct trie {
    int isLeaf;
    trie *nodes[MAX_NODES];

    trie() {
        memset(nodes, 0, sizeof nodes);
        isLeaf = -2;
    }

    void insert(char *str, int id) {
        if (*str == '\0') return isLeaf = id, void();

        int cur = *str - 'a';
        if (nodes[cur] == 0) nodes[cur] = new trie();

        nodes[cur]->insert(str + 1, id);
    }

    int find(char *str) {
        if (*str == '\0') return isLeaf;

        int cur = *str - 'a';
        if (nodes[cur] == 0) return -1;

        return nodes[cur]->find(str + 1);
    }
} *tree;

int dp(int i) {
    if (i == n) return 1;

    int &ret = memo[i];
    if (~ret) return ret;

    ret = 0;
    trie *x = tree;
    for (int j = i, val; j < n && ret == 0; ++j) {
        val = s[j] - 'a';

        if (x->nodes[val] == 0) break;
        if (x->nodes[val]->isLeaf >= 0) ret |= dp(j + 1);

        x = x->nodes[val];
    }

    return ret;
}

void build(int i) {
    if (i == n) return;

    int ret = memo[i];

    trie *x = tree;
    int nxt = -1;
    for (int j = i, val; j < n; ++j) {
        val = s[j] - 'a';

        if (x->nodes[val] == 0) break;
        if (x->nodes[val]->isLeaf >= 0) {
            if (ret == dp(j + 1)) {
                ans.push_back(x->nodes[val]->isLeaf), nxt = j + 1;
                break;
            }
        }
        x = x->nodes[val];
    }

    build(nxt);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif /*ONLINE_JUDGE*/

    cin >> n >> s >> m;
    for (int i = 0; i < m; i++) cin >> words[i];

    tree = new trie();
    for (int i = 0; i < m; i++) {
        temp = words[i];

        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        reverse(temp.begin(), temp.end());
        tree->insert(&temp[0u], i);
    }

    memset(memo, -1, sizeof memo);
    dp(0), build(0);

    for (int i = 0; i < ans.size(); i++)
        cout << words[ans[i]] << " \n"[i + 1 == ans.size()];

    return 0;
}

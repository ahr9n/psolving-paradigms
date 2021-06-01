#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

struct node{
    string T;
    node *left, *right;
    node(string type): T(type), left(NULL), right(NULL){}
} *root;

int n, cnt = 0;
string s;

node* BST() {
    if (!(cin >> s)) return NULL;
    node *now = new node(s);

    if (s == "int") return ++cnt, now;

    now->left = BST();
    if (now->left == NULL) return NULL;

    now->right = BST();
    if (now->right == NULL) return NULL;

    return now;
}

void print(node *root) {
    if (root->T == "int") return cout << root->T, void();
    cout << "pair<", print(root->left); cout << ",", print(root->right), cout << ">";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;
    root = BST();
    if (root == NULL || cnt != n || (cin >> s))
        return puts("Error occurred"), 0;

    print(root);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void PreOrder(TreeNode * node, vector < int > & ans) {
    if (node == NULL) return;

    ans.push_back(node -> val);
    PreOrder(node -> left, ans);
    PreOrder(node -> right, ans);
}

void PostOrder(TreeNode * node, vector < int > & ans) {
    if (node == NULL) return;

    PostOrder(node -> left, ans);
    PostOrder(node -> right, ans);
    ans.push_back(node -> val);
}


void InOrder(TreeNode * node, vector < int > & ans) {
    if (node == NULL) return;

    InOrder(node -> left, ans);
    ans.push_back(node -> val);
    InOrder(node -> right, ans);
}

int main() {


    TreeNode * root = new TreeNode(1);

    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);

    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);

    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);

    vector < int > pre, post, in;

    PreOrder(root, pre);
    PostOrder(root, post);
    InOrder(root, in);

    cout << "Preorder: ";
    for (auto it : pre) cout << it << " ";

    cout << "\nPostorder: ";
    for (auto it: post) cout << it << " ";

    cout << "\nInorder: ";
    for (auto it: in) cout << it << " ";

    return 0;
}

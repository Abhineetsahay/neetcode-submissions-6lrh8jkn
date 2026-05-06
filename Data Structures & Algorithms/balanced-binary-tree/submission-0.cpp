/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    int trav(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = trav(root->left);
        int right = trav(root->right);

        if (abs(left - right) > 1 || left == -1 || right == -1) return -1;

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) { return trav(root) != -1; }
};

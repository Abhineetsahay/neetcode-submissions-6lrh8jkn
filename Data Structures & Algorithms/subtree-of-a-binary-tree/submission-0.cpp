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
    bool sameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        if (p->val == q->val) {
            return sameTree(p->left, q->left) && sameTree(p->right, q->right);
        }
        return false;
    }
    bool has_subtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }

        if (sameTree(root, subRoot)) {
            return true;
        }

        return has_subtree(root->left, subRoot) || has_subtree(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) { return has_subtree(root, subRoot); }
};

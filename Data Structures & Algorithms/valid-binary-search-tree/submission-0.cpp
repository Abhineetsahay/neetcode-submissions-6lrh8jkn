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
   private:
    bool isValid(TreeNode* root, int left, int right) {
        if (root == nullptr) return true;

        if (root->val <= left || root->val >= right) return false;

        return isValid(root->left, left, root->val) && isValid(root->right, root->val, right);
    }

   public:
    bool isValidBST(TreeNode* root) { return isValid(root, INT_MIN, INT_MAX); }
};

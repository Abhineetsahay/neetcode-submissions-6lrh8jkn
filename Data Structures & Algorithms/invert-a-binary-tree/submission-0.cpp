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
    void trav(TreeNode* root) {
        if (root == nullptr) return;
        swap(root->left, root->right);
        trav(root->left);
        trav(root->right);
    }

   public:
    TreeNode* invertTree(TreeNode* root) {
        trav(root);
        return root;
    }
};

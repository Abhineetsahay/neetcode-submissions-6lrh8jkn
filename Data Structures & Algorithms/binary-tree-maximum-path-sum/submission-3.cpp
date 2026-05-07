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
    int trav(TreeNode* root, int& maxVal) {
        if (root == nullptr) return 0;

        int left = max(0, trav(root->left, maxVal));
        int right = max(0, trav(root->right, maxVal));

        maxVal = max(maxVal, root->val + left + right);

        return root->val + max(left, right);
    }

   public:
    int maxPathSum(TreeNode* root) {
        int maxVal = root->val;
        trav(root, maxVal);
        return maxVal;
    }
};

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
    int f(TreeNode* root, int maxVal) {
        if (root == nullptr) return 0;

        int ans = 0;
        if (root->val >= maxVal) {
            ans += 1;
        }
        maxVal = max(maxVal, root->val);
        ans += f(root->left, maxVal);
        ans += f(root->right, maxVal);
        return ans;
    }

   public:
    int goodNodes(TreeNode* root) { return f(root, root->val); }
};

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
    void trav(TreeNode* root, vector<int>& res, int level) {
        if (root == nullptr) return;
        if (level == res.size()) {
            res.push_back(root->val);
        }
        trav(root->right, res, level + 1);
        trav(root->left, res, level + 1);
    }

   public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        trav(root, res, 0);
        return res;
    }
};

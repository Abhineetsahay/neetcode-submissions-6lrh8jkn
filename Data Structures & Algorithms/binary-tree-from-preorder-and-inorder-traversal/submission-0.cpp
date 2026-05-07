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
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorder_map, int st, int ed,
                    int& posInd) {
        if (st > ed) return nullptr;

        int val = preorder[posInd++];
        TreeNode* Node = new TreeNode(val);
        int pos = inorder_map[val];

        Node->left = build(preorder, inorder_map, st, pos - 1, posInd);
        Node->right = build(preorder, inorder_map, pos + 1, ed, posInd);
        return Node;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < n; i++) {
            inorder_map[inorder[i]] = i;
        }
        int posInd=0;
        return build(preorder, inorder_map, 0, n - 1, posInd);
    }
};

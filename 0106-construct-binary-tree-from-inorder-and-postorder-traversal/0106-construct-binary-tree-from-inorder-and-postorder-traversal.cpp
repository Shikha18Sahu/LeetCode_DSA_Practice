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
    unordered_map<int,int> mp;

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int postEnd,int inStart,int inEnd) {
        if (inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int idx = mp[root->val];
        int rightSize = inEnd - idx;
        root->right = solve(inorder, postorder, postEnd - 1,idx + 1, inEnd);
        root->left = solve(inorder, postorder,postEnd - rightSize - 1,inStart,idx - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return solve(inorder, postorder,postorder.size() - 1,0,inorder.size() - 1);
    }
};
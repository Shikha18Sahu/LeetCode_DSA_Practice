class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr) {
            if (curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;

                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    ans.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};
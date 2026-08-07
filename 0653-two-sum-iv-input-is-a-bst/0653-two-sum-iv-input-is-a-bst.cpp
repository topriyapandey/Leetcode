class Solution {
public:
    vector<int> inorder;

    void solve(TreeNode* root) {
        if (root == NULL) return;

        solve(root->left);
        inorder.push_back(root->val);
        solve(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        solve(root);

        int i = 0, j = inorder.size() - 1;

        while (i < j) {
            int sum = inorder[i] + inorder[j];

            if (sum == k)
                return true;
            else if (sum < k)
                i++;
            else
                j--;
        }

        return false;
    }
};
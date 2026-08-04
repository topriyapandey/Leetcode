class BSTIterator {
public:
    stack<TreeNode*> st;

    void pushAll(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (node->right)
            pushAll(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
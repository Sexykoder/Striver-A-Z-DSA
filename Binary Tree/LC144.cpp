// Given the root of a binary tree, return the preorder traversal of its nodes' values.

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans; 
        if (root == nullptr) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            if (root->right != nullptr) st.push(root->right);
            if (root->left != nullptr) st.push(root->left);
        }
        return ans;
    }
};


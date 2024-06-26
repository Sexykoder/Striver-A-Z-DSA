//145. Binary Tree Postorder Traversal


//Recursive Approach
class Solution {
public:
    void postOrder(TreeNode* root, vector<int> &ans) {
        if(root == nullptr) return;
        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};
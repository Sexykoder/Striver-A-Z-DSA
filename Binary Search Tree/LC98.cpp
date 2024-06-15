// BRUTE
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        check(root,ans);
        for(int i=0; i<ans.size()-1;i++) {
            if(ans[i]>=ans[i+1]) return false;
        }
        return true;  
    }
    void check(TreeNode* root, vector<int> &ans) {
        if(root == NULL) return;
        check(root->left,ans);
        ans.push_back(root->val);
        check(root->right,ans);
    }
};
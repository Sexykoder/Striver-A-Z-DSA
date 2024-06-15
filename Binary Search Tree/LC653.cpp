class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,k,ans);
        int i=0,j=ans.size()-1;
        while(i<j){
            if(ans[i]+ans[j] > k) j--;
            else if(ans[i]+ans[j] < k) i++;
            else return true;
        }
        return false;
        
    }
    void inorder(TreeNode* root, int k , vector<int>&ans) {
        if(root == NULL) return;
        inorder(root->left,k,ans);
        ans.push_back(root->val);
        inorder(root->right,k,ans);
    }
};
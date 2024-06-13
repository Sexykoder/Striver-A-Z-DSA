class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // Calculate the maximum path sum for the left and right subtrees
        int leftMax = max(0, maxPathSumHelper(node->left, maxSum));
        int rightMax = max(0, maxPathSumHelper(node->right, maxSum));

        // Update the maximum path sum considering the current node
        maxSum = max(maxSum, leftMax + rightMax + node->val);

        // Return the maximum sum considering the current node in the path
        return max(leftMax, rightMax) + node->val;
    }
};
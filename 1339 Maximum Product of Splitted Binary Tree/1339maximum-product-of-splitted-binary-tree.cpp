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
    long long totalSum = 0;
    long long max_product = 0;
    static const long long MOD = 1000000007;

    long long treeSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + treeSum(root->left) + treeSum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long curr =
            root->val + dfs(root->left) + dfs(root->right);

        long long product = curr * (totalSum - curr);
        max_product = max(max_product, product);

        return curr;
    }

    int maxProduct(TreeNode* root) {
        totalSum = treeSum(root);  // 1st DFS
        dfs(root);                 // 2nd DFS
        return max_product % MOD;
    }
};
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
    int ans = 0;
    unordered_map<long long, int> mp;

    void dfs(TreeNode* root, long long currSum, int targetSum) {
        if (!root) return;

        currSum += root->val;

        // Case 1: Path from root itself
        if (currSum == targetSum)
            ans++;

        // Case 2: Path ending here but starting somewhere in middle
        if (mp.count(currSum - targetSum))
            ans += mp[currSum - targetSum];

        // Store current prefix sum
        mp[currSum]++;

        dfs(root->left, currSum, targetSum);
        dfs(root->right, currSum, targetSum);

        // Backtrack
        mp[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp.clear();
        ans = 0;
        dfs(root, 0, targetSum);
        return ans;
    }
};
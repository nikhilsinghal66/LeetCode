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
    TreeNode* prev=nullptr;
    void find_min(TreeNode* root,int &mini){
        if(!root) return ;
        find_min(root->left,mini);
        if(prev){
            mini=min(mini,abs(root->val-prev->val));
        }
        prev=root;
        find_min(root->right,mini);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        find_min(root,mini);
        return mini;
    }
    // such a easy question but still figuring out the logics,such a stupid guy i am...
};
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
    int find_depth(TreeNode* root){
        if(root==NULL) return 0;
        int lh=find_depth(root->left);
        int rh=find_depth(root->right);
        return 1+max(lh,rh);

    }
    int maxDepth(TreeNode* root) {
        int result=find_depth(root);
        return result;
    }
};
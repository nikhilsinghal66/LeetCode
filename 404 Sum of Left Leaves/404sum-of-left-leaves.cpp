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
    void find_leaf(TreeNode* root,int &suml) {
        if(!root) return ;
        if(root->left && !root->left->left && !root->left->right){
            suml+=root->left->val;
        }
        find_leaf(root->left,suml);
        find_leaf(root->right,suml);
    }
    int sumOfLeftLeaves(TreeNode* root){
        int suml=0;
        find_leaf(root,suml);
        return suml;
    }
};
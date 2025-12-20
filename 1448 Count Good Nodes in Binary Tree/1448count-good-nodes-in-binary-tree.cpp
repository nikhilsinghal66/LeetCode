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
    void find_good_nodes(TreeNode* root, int &good_nodes,int maxi){
        if(!root) return;
        if(root->val>=maxi){
            good_nodes++;
        }
        maxi=max(maxi,root->val);
        if(root->left) find_good_nodes(root->left,good_nodes,maxi);
        if(root->right) find_good_nodes(root->right,good_nodes,maxi);
    }

    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN;
        int good_nodes=0;
        find_good_nodes(root,good_nodes,maxi);
        return good_nodes;
    }
};
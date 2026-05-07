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
    void leaf(TreeNode* root,vector<int> &leaf1){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            leaf1.push_back(root->val);
            return ;
        }
        if(root->left!=NULL) leaf(root->left,leaf1);
        if(root->right!=NULL) leaf(root->right,leaf1);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        leaf(root1,leaf1);
        vector<int> leaf2;
        leaf(root2,leaf2);
        if(leaf1.size()!=leaf2.size()) return false;
        for(int i=0;i<leaf1.size();i++){
            if(leaf1[i]!=leaf2[i]){
                return false;
            }
        }
        return true;
    }
};
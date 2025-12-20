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
    int find(TreeNode* root,int &maxi){
        if(!root) return 0;
        int lh=find(root->left,maxi);
        if(lh==-1) return -1;
        int rh=find(root->right,maxi);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        int maxi=0;
        int result=find(root,maxi);
        return result!=-1?true:false;
    }
};
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
    TreeNode* buildtree(vector<int> &postorder,int poststart,int postend,vector<int> &inorder,int instart,int inend,map<int,int> &mpp){
        if(instart>inend || poststart>postend) return NULL;
        TreeNode* root=new TreeNode(postorder[postend]);
        int inpos=mpp[root->val];
        int numsize=inpos-instart;
        root->left=buildtree(postorder,poststart,poststart+numsize-1,inorder,instart,instart+numsize,mpp);
        root->right=buildtree(postorder,poststart+numsize,postend-1,inorder,inpos+1,inend,mpp);
        return root;
    }




    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=buildtree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;  
    }
};
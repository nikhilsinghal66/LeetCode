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

    void make_parent(map<TreeNode*,TreeNode*> &mpp, TreeNode* root,TreeNode* &startnode,int start){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* it=q.front();
            q.pop();
            if(it->val==start){
                startnode=it;
            }
            if(it->left){
                mpp[it->left]=it;
                q.push({it->left});
            }
            if(it->right){
                mpp[it->right]=it;
                q.push({it->right});
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> mpp;
        queue<TreeNode*> q;
        TreeNode* startnode=NULL;
        make_parent(mpp,root,startnode,start);
        unordered_map<TreeNode* , bool> visited;
        int cur_level=-1;
        q.push(startnode);
        visited[startnode]=true;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    visited[node->right]=true;
                    q.push(node->right);
                }
                if(mpp[node] && !visited[mpp[node]]){
                    visited[mpp[node]]=true;
                    q.push(mpp[node]);                
                }
            }
            cur_level=cur_level+1;
        }
        return cur_level;
    }
};
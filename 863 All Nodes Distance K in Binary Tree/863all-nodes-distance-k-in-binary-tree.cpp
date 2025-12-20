/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void find_parent(TreeNode* root, map<TreeNode*,TreeNode*> &mpp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        map<TreeNode*,TreeNode*> mpp;
        find_parent(root,mpp);
        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        visited[target]=true;
        int cur_level=0;
        while(!q.empty()){
            int size1=q.size();
            if(cur_level==k) break;
            for(int i=0;i<size1;i++){
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
            cur_level++;
        }
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;   
    }
};
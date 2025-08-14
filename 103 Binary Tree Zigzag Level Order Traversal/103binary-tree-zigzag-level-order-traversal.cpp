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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        queue<TreeNode* > q;
        q.push(root);
        vector<vector<int>> ans;
        bool flag=true;
        if (!root) return ans;
        while(!q.empty()){
            int size1=q.size();
            vector<int> level(size1);
            for(int i=0;i<size1;i++){
                TreeNode* node=q.front();
                q.pop();
                int index=flag? i: size1-i-1;
                level[index]=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);

            }
            ans.push_back(level);
            flag=!flag;
        }
        return ans;   
    }
};
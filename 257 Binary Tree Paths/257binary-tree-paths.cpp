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
    void find_path(TreeNode* root,vector<int> &str,vector<vector<int>> &ans){
        if(!root) return;
        str.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(str);
            str.pop_back();
            return ;
        }
        if(root->left) find_path(root->left,str,ans);
        if(root->right) find_path(root->right,str,ans);
        str.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> str1;
        vector<vector<int>> ans;
        vector<string> result;
        find_path(root,str1,ans);
        int size=ans.size();
        for(int i=0;i<size;i++){
            int size1=ans[i].size();
            string str2="";
            for(int j=0;j<size1;j++){
                if(j==size1-1){
                    str2+=to_string(ans[i][j]);
                    break;
                }
                str2+=to_string(ans[i][j])+"->";
            }
            result.push_back(str2);
        }
        return result;  
    }
};
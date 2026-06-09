class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        //Brute force ...
        int n=mat.size();
        int m=mat[0].size();
        int ind=0;
        if(n * m != r * c) {
            return mat;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(mat[i][j]);
            }
        }
        vector<vector<int>> ans1(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans1[i][j]=ans[ind++];
            }
        }
        return ans1; 
    }
};
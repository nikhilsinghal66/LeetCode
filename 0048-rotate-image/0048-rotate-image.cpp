class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Optimal Approach...
        int n=matrix.size();
        vector<vector<int>> ans=matrix;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[j][n-i-1]=ans[i][j];
            }
        }
        
    }
};
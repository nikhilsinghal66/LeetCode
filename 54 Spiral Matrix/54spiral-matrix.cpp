class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        int layers=(min(n,m)+1)/2;
        for(int i=0;i<layers;i++){
            //First row... 
            for(int j=i;j<m-i;j++){
                ans.push_back(matrix[i][j]);
            }
            //last column...
            for(int j=i+1;j<n-i;j++){
                ans.push_back(matrix[j][m-1-i]);
            }
            //last row...
            if(n-1-i!=i){
            for(int j=m-2-i;j>=i;j--){
                ans.push_back(matrix[n-1-i][j]);
            }
            }
            //first column...
            if(m-1-i!=i){
            for(int j=n-2-i;j>i;j--){
                ans.push_back(matrix[j][i]);
            }
            }
        }
        return ans;
    }
};
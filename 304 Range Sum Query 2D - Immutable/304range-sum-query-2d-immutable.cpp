class NumMatrix {
public:
    vector<vector<int>> real;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> prefix_matrix(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefix_matrix[i][j]=matrix[i-1][j-1]+ prefix_matrix[i-1][j]+prefix_matrix[i][j-1]-prefix_matrix[i-1][j-1];
            }
        }
        real=prefix_matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        ans=real[row2+1][col2+1]-real[row1][col2+1]-real[row2+1][col1]+real[row1][col1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
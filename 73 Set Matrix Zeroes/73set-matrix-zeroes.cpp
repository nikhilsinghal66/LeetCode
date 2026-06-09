class Solution {
public:
    void f(vector<vector<int>> &matrix,int row,int col,int n,int m){
        //Traversing the whole column...
        for(int j=0;j<n;j++){
            matrix[j][col]=0;
        }
        //Traversing the whole row...
        for(int j=0;j<m;j++){
            matrix[row][j]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> sample=matrix;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(sample[i][j]==0){
                    f(matrix,i,j,n,m);
                }
            }
        }
    }
};
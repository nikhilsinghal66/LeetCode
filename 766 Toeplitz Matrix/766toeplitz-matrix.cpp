class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==1 && m==1) return true;
        //Row checking...
        for(int i=1;i<n;i++){
            int row=i;
            int col=1;
            int check=matrix[row-1][col-1];
            while(row<n && col<m){
                if(matrix[row][col]!=check){
                    return false;
                }
                col++;
                row++;
            }
        }
        //col checking...
        for(int i=1;i<m;i++){
            int row=1;
            int col=i;
            int check=matrix[row-1][col-1];
            while(col<m && row<n){
                if(matrix[row][col]!=check){
                    return false;
                }
                row++;
                col++;
            }
        }
        return true;
    }
};
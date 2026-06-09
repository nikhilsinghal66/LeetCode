class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> ans;
        int dir=1;
        int row=0;
        int col=0;
        while(ans.size()<n*m){
            ans.push_back(mat[row][col]);
            if(dir==1){
                if(col==m-1){
                    row++;
                    dir=-1;
                }
                else if(row==0){
                    col++;
                    dir=-1;
                }
                else{
                    row--;
                    col++;
                }
            }
            else{
                if(row==n-1){
                    col++;
                    dir=1;
                }
                else if(col==0){
                    row++;
                    dir=1;
                }
                else{
                    row++;
                    col--;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<pair<int,int>,int> mpp;
        //primary_diagonal...sum
        int ind=min(n,m);
        int sum=0;
        int row=0;
        int col=0;
        for(int i=0;i<ind;i++){
            sum+=mat[row][col];
            mpp[{row,col}]++;
            row++;
            col++;
        }
        //secondary_diagonal...sum
        int row1=0;
        int col1=m-1;
        for(int i=0;i<ind;i++){
            sum+=mat[row1][col1];
            mpp[{row1,col1}]++;
            row1++;
            col1--;
        }
        for(auto it:mpp){
            if(it.second==2){
                sum-=mat[it.first.first][it.first.second];
            }
        }
        return sum; 
    }
};
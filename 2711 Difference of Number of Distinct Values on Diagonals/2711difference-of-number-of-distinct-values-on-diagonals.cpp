class Solution {
public:
    void f(vector<vector<int>>& grid,int &left, int &right,int row,int col){
        int n=grid.size();
        int m=grid[0].size();
        set<int> left1;
        set<int> right1;
        int row1=row-1;
        int col1=col-1;
        //going upward..
        while(row1>=0 && col1>=0){
            left1.insert(grid[row1][col1]);
            row1--;
            col1--;
        }
        //going downward...
        int row2=row+1;
        int col2=col+1;
        while(row2<n && col2<m){
            right1.insert(grid[row2][col2]);
            row2++;
            col2++;
        }
        left=left1.size();
        right=right1.size();
    }

    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int left=0;
                int right=0;
                f(grid,left,right,i,j);
                ans[i][j]=abs(right-left);
            }
        }
        return ans;
    }
};
class Solution {
public:
    void f(vector<vector<int>>& temp,vector<vector<int>>& grid){
        // i to m-1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                temp[j][i]=grid[j][i-1];
            }
        }
        //gird[i][n-1] to grid[i+1][0]...
        for(int i=1;i<n;i++){
            temp[i][0]=grid[i-1][m-1];
        }
        //grid[m-1][n-1] to grid[0][0]...
        temp[0][0]=grid[n-1][m-1];
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> temp=grid;
        while(k--){
            f(temp,grid);
            grid=temp;
        }
        return temp; 
    }
};
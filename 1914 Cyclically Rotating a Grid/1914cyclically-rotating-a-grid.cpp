class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        //Start loop for n/2 (no. of layer)...
        int size1=min(n/2,m/2);
        int row1=0,col1=0,rown=n-1,coln=m-1;
        for(int i=0;i<size1;i++){
            vector<int> temp;
            // int row1=0,col1=0,rown=n-1,coln=m-1;
            //row 1 ...
            for(int j=col1;j<=coln;j++){
                temp.push_back(grid[row1][j]);
            }
            //last column...
            for(int j=row1+1;j<=rown-1;j++){
                temp.push_back(grid[j][coln]);
            }
            //last row...
            for(int j=coln;j>=col1;j--){
                temp.push_back(grid[rown][j]);
            }
            //first column...
            for(int j=rown-1;j>=row1+1;j--){
                temp.push_back(grid[j][col1]);
            }
            //lets rotate...
            int len=temp.size();
            int rot=k%len;
            reverse(temp.begin(),temp.begin()+rot);
            reverse(temp.begin()+rot,temp.end());
            reverse(temp.begin(),temp.end());
            //Putting rotating elements on their respecting position...
            int l=0;
            for(int j=col1;j<=coln;j++){
                grid[row1][j]=temp[l];
                l++;
            }
            //last column...
            for(int j=row1+1;j<=rown-1;j++){
                grid[j][coln]=temp[l];
                l++;
            }
            //last row...
            for(int j=coln;j>=col1;j--){
                grid[rown][j]=temp[l];
                l++;
            }
            //first column...
            for(int j=rown-1;j>=row1+1;j--){
                grid[j][col1]=temp[l];
                l++;
            }
            //next layer...
            row1=row1+1;
            col1=col1+1;
            rown=rown-1;
            coln=coln-1;
        }
        return grid;
    }
};
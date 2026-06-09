class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int ans1=1;
        int m=(n+1)/2;
        for(int i=0;i<m;i++){
            //first row...
            for(int j=i;j<n-i;j++){
                ans[i][j]=ans1++;
            }
            //last column...
            for(int j=i+1;j<n-i;j++){
                ans[j][n-i-1]=ans1++;
            }
            //last row...
            for(int j=n-2-i;j>=i;j--){
                ans[n-i-1][j]=ans1++;
            }
            //first column...
            for(int j=n-2-i;j>i;j--){
                ans[j][i]=ans1++;
            }
        }
        return ans;
    }
};
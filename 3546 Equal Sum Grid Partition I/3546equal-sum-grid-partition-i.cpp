class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n<2 && m<2){
            return false;
        }

        long long total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total+=grid[i][j];
            }
        }
        if(total%2!=0) return false;
        long long ans2=0;
        for(int i=0;i<n;i++){
            long long temp=0;
            for(int j=0;j<m;j++){
                temp+=grid[i][j];
            }
            ans2+=temp;
            if(ans2==total/2 && ans2*2==total) return true;
        }
        long long  ans1=0;
        for(int j=0;j<m;j++){
            long long temp=0;
            for(int i=0;i<n;i++){
                temp+=grid[i][j];
            }
            ans1+=temp;
            if(ans1==total/2 && ans1*2==total) return true;
        }
        return false;
    }
};
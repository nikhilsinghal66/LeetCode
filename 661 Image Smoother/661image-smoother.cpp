class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // Lets try all elements ...
                long long sum=0;
                int count=0;
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        int nrow=i+k;
                        int ncol=j+l;
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                            count++;
                            sum+=img[nrow][ncol];
                        }
                    }
                }
                ans[i][j]=sum/count;
            }
        }
        return ans;  
    }
};
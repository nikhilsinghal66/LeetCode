class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            vector<int> col_sum(m,0);
            for(int top=i;top<n;top++){
                for(int j=0;j<m;j++){
                    col_sum[j]+=matrix[top][j];
                }
                //Now check ... prefix_sum...
                unordered_map<int,int> mpp;
                mpp[0]=1;
                int prefix_sum=0;
                for(int k=0;k<m;k++){
                    prefix_sum+=col_sum[k];
                    count+=mpp[prefix_sum-target];
                    mpp[prefix_sum]++;
                }
            }
        }
        return count;
    }
};
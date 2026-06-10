class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            vector<int> temp=matrix[i];
            sort(temp.rbegin(),temp.rend());
            for(int j=0;j<m;j++){
                sum=max(sum,temp[j]*(j+1));
            }
        }
        return sum;
    }
};
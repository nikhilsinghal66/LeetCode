class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int l=0;
            int r=m-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(target==matrix[i][mid]){
                    return true;
                }
                if(target<matrix[i][mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }
        return false;
    }
};
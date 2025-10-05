class Solution {
public:

    int find_max(vector<vector<int>> & mat , int col){
        int max_el=mat[0][col];
        int index=0;
        int n=mat.size();
        for(int i=0;i<n;i++){
            if(max_el<mat[i][col]){
                max_el=mat[i][col];
                index=i;
            }
            // max_el=max(max_el, mat[i][col]);
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=find_max(mat,mid);
            int left=(mid-1>=0)? mat[row][mid-1]:-1;
            int right=(mid+1<m)? mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<right){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return {-1,-1};
        
    }
};
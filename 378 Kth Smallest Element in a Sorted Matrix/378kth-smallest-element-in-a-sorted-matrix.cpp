class Solution {
public:
    int find_count(vector<vector<int>> &matrix,int mid){
        int count=0;
        int row=matrix.size()-1;
        int col=0;
        int m=matrix[0].size();
        while(row>=0 && col<m){
            if(matrix[row][col]<=mid){
                count+=row+1;
                col++;
            }
            else{
                row--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=matrix[0][0];
        int high=matrix[n-1][m-1];
        while(low<=high){
            int mid=(low+high)/2;
            int count=find_count(matrix,mid);
            if(count<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
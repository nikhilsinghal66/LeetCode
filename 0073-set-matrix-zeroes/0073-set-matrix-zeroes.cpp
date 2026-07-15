class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //Optimal approach...
        int n=matrix.size();
        int m=matrix[0].size();
        int row=-1;
        int col=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if(i==0){
                        row=1;
                    }
                    if(j==0){
                        col=1;
                    }
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<m;j++){
                    if(i==0 || j==0){
                        continue;
                    }
                    else{
                        matrix[i][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            if(matrix[0][i]==0){
                for(int j=0;j<n;j++){
                    if(i==0 || j==0){
                        continue;
                    }
                    else{
                        matrix[j][i]=0;
                    }
                }
            }
        }
        if(row==1){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }
        if(col==1){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
    }
};
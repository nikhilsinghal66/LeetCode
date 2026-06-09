class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> copy=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        if(k==0 && l==0) continue;
                        int nrow=i+k;
                        int ncol=j+l;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                            count+=copy[nrow][ncol];
                        }
                    }
                }
                if(copy[i][j]==0){
                    if(count==3){
                        board[i][j]=1;
                    }
                }
                else{
                    if(count<2){
                        board[i][j]=0;
                    }
                    else if(count==2 || count==3){
                        board[i][j]=1;
                    }
                    else{
                        board[i][j]=0;
                    }
                }
            }
        } 
    }
};
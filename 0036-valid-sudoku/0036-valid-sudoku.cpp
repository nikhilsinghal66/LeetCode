class Solution {
public:
    bool f(int row,int col,vector<vector<char>> &board){
        set<char> st;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[row+i][col+j]!='.' && st.find(board[row+i][col+j])!=st.end()){
                    return false;
                }
                else{
                    st.insert(board[row+i][col+j]);
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            set<char> st;
            for(int j=0;j<m;j++){
                if(board[i][j]!='.' &&  st.find(board[i][j])!=st.end()){
                    return false;
                }
                else{
                    st.insert(board[i][j]);
                }
            }
        }
        for(int i=0;i<m;i++){
            set<char> st;
            for(int j=0;j<n;j++){
                if(board[j][i]!='.' && st.find(board[j][i])!=st.end()){
                    return false;
                }
                else{
                    st.insert(board[j][i]);
                }
            }
        }
        vector<int> delrow={0,3,6};
        vector<int> delcol={0,3,6};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int row=delrow[i];
                int col=delcol[j];
                if(f(row,col,board)==false){
                    return false;
                }
            }
        }
        return true; 
    }
};
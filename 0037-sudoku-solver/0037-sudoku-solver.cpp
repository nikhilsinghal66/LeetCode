class Solution {
public:
    bool f(vector<vector<char>>& board,unordered_map<int,set<char>> &row_set,unordered_map<int,set<char>> &col_set,unordered_map<int,set<char>> &grid3_set,int n,int m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'){
                    for(int num=1;num<=9;num++){
                        char ch=num+'0';
                        if(row_set[i].count(ch) || col_set[j].count(ch) || 
                        grid3_set[(i/3)*3 + j/3].count(ch)){
                            continue;
                        }
                        board[i][j]=ch;
                        row_set[i].insert(ch);
                        col_set[j].insert(ch);
                        grid3_set[(i/3)*3 + j/3].insert(ch);
                        if(f(board,row_set,col_set,grid3_set,n,m)){
                            return true;
                        }
                        board[i][j]='.';
                        row_set[i].erase(ch);
                        col_set[j].erase(ch);
                        grid3_set[(i/3)*3 + j/3].erase(ch);
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        unordered_map<int,set<char>> row_set;
        unordered_map<int,set<char>> col_set;
        unordered_map<int,set<char>> grid3_set;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!='.'){
                    char ch=board[i][j];
                    row_set[i].insert(ch);
                    col_set[j].insert(ch);
                    int bord=(i/3)*3 + j/3;
                    grid3_set[bord].insert(ch);
                }
            }
        }
        f(board,row_set,col_set,grid3_set,n,m);
    }
};
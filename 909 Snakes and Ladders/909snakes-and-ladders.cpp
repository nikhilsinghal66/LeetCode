class Solution {
public:
    vector<int> getcoordinates(int num,int n){
        int r=(num-1)/n;
        int c=(num-1)%n;
        int row=n-1-r;
        if(r%2==1){
            c=n-1-c;
        }
        return {row,c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        //{num,moves}...
        queue<pair<int,int>> q;
        vector<int> vis(n*n+1,0);
        q.push({1,0});
        vis[1]=1;
        while(!q.empty()){
            int num=q.front().first;
            int moves=q.front().second;
            q.pop();
            if(num==n*n) return moves;
            for(int i=1;i<=6;i++){
                int num_board=num+i;
                if(num_board>n*n) break;
                vector<int> rc=getcoordinates(num_board,n);
                int row=rc[0];
                int col=rc[1];
                if(board[row][col]!=-1){
                    num_board=board[row][col];
                }
                if(!vis[num_board]){
                    q.push({num_board,moves+1});
                    vis[num_board]=1;
                }
            }
        }
        return -1;
    }
};
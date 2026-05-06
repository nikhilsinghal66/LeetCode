class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int value=image[sr][sc];
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        vis[sr][sc]=1;
        q.push({sr,sc});
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        image[sr][sc]=color;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
                image[nrow][ncol]==value){
                    image[nrow][ncol]=color;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
        
    }
};
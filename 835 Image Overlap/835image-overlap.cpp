class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int m=img1[0].size();
        vector<pair<int,int>> A,B;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(img1[i][j]==1){
                    A.push_back({i,j});
                }
                if(img2[i][j]==1){
                    B.push_back({i,j});
                }
            }
        }
        //...
        map<pair<int,int>,int> mpp;
        int ans=0;
        for(auto a : A){
            for(auto b: B){
                pair<int,int> shift={b.first-a.first,b.second-a.second};
                mpp[shift]++;
                ans=max(ans,mpp[shift]);
            }
        }
        return ans;   
    }
};
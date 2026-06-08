class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(points.size()==0) return 0;
        sort(points.begin(),points.end());
        int counter=points[0][1];
        int ans=1;
        for(int i=1;i<n;i++){
            int a0=points[i][0];
            int a1=points[i][1];
            if(counter<a0){
                ans++;
                counter=a1;
            }
            else{
                counter=min(counter,a1);
            }
        }
        return ans;
    }
};
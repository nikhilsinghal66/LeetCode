class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int left=newInterval[0];
        int right=newInterval[1];
        vector<vector<int>> ans;
        bool check=false;
        for(int i=0;i<n;i++){
            int a0=intervals[i][0];
            int a1=intervals[i][1];
            //case 1 (starting phase)...
            if(a1<left){
                ans.push_back({a0,a1});
            }
            //case 2 (last phase)...
            else if(right<a0){
                if(check==false){
                    ans.push_back({left,right});
                    check=true;
                }
                ans.push_back({a0,a1});
            }
            //case 3 (middle phase)...
            else{
                left=min(a0,left);
                right=max(a1,right);
            }
        }
        if(check==false){
            ans.push_back({left,right});
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){
            return a[0]<b[0];
        });
        vector<vector<int>> ans;
        int left=intervals[0][0];
        int right=intervals[0][1];
        for(int i=1;i<n;i++){
            int a0=intervals[i][0];
            int a1=intervals[i][1];
            if(right<a0){
                ans.push_back({left,right});
                left=a0;
                right=a1;
                continue;
            }
            else{
                left=min(a0,left);
                right=max(a1,right);
            }
        }
        ans.push_back({left,right});
        return ans;
    }
};
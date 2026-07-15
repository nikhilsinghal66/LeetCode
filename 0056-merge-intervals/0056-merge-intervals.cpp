class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];
        vector<vector<int>> ans;
        for(int i=1;i<n;i++){
            int a1=intervals[i][0];
            int a2=intervals[i][1];
            if(a1<=temp[1]){
                temp[0]=min(temp[0],a1);
                temp[1]=max(temp[1],a2);
            }
            else{
                ans.push_back(temp);
                temp=intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
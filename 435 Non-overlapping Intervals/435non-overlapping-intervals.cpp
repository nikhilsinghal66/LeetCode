class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        //sorting it...
        sort(intervals.begin(),intervals.end(),[](vector<int> &a , vector<int> &b){
            return a[1]<b[1];
        });
        int res=intervals[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            int a1=intervals[i][1];
            if(res > intervals[i][0]){
                cnt++;
            }
            else{
                res=a1;
            }
        }
        return cnt; 
    }
};